// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 1e6 + 10;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

struct Prob {
	map<int, double> a;
	// prob = (a_0 s_0 + a_1 s_1 + ... + b) / c;
	double b;

	Prob() {}
	Prob(double b) : b(b) {}
	Prob(map<int, double> &a, double b) : a(a), b(b) {}

	void print() {}
};

Prob operator+(const Prob &x, const Prob &y) {
	Prob z = Prob(x.b + y.b);
	for (auto sv : x.a) {
		z.a[sv.first] += sv.second;
	}
	for (auto sv : y.a) {
		z.a[sv.first] += sv.second;
	}
	return z;
}

Prob operator/(const Prob &x, const double k) {
	Prob z = Prob(x.b / k);
	for (auto sv : x.a) {
		z.a[sv.first] = sv.second / k;
	}
	return z;
}

int n;
Prob pd[31][31];
double pd2[31][31];
string a, b;

int rematch_pd[200];

int rematch(int sn, int matched, char c) {
	int cd = matched * 4 + 2*int(c == '1') + sn;
	if (rematch_pd[cd] != -1) return rematch_pd[cd];

	string x;
	if (sn == 0) x = a;
	else x = b;

	if (x[matched] == c) return matched+1;
	// it doesn't match from the beggining anymore
	// can be improved with kmp
	for (int i = 1; i < matched; i++) {
		bool match = true;
		for (int j = i; j < matched; j++) {
			if (x[j-i] != x[j]) {
				match = false;
				break;
			}
		}

		if (match && x[matched-i] == c) {
			return rematch_pd[cd] = matched+1 - i;
		}
	}

	return rematch_pd[cd] = int(x[0] == c);
}

Prob solve(ll ma, ll mb) {
	if (ma == n) return Prob(1.0);
	if (mb == n) return Prob(0.0);

	int s = n * ma + mb;

	if (pd[ma][mb].b == -2.0) {
		Prob res = Prob(0.0);
		res.a[s] = 1.0;
		return res;
	}

	if (pd[ma][mb].b != -1.0) return pd[ma][mb];

	pd[ma][mb].b = -2.0;

	Prob p0 = solve(rematch(0, ma, '0'), rematch(1, mb, '0'));
	Prob p1 = solve(rematch(0, ma, '1'), rematch(1, mb, '1'));

	Prob res = (p0 + p1) / 2.0;

	if (res.a.find(s) != res.a.end()) {
		// depends on itself!
		// s_x = s_0 a_0 + ... + s_x a_x + b
		// s_x = s_0 a_0 + ... + s_x a_x + b
		// s_x (1 - a_x) = s_0 a_0 + ... + b
		// s_x = (s_0 a_0 + ... + b) / (1 - a_x)
		assert(res.a[s] != 1.0);
		res = res / (1.0 - res.a[s]);
		res.a.erase(s);
	}

	return pd[ma][mb] = res;
}

void build() {
	for (int i = 0; i < n; i++) {
		pd2[i][n] = 0.0;
		pd2[n][i] = 1.0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pd2[i][j] = double(rand()) / RAND_MAX;
		}
	}
}

int it = 0;
double d_change[31][31];
vector<pair<int, int>> itps;

double iterate() {
	it++;
	if (it % (max(20, 2*n)) == 0)  {
		vector<pair<int,int>> nitps;
		for (auto itp : itps) {
			int i = itp.first;
			int j = itp.second;
			if (d_change[i][j] > 1e-4) {
				d_change[i][j] = 0.0;
				nitps.push_back(itp);
			}
		}
		swap(nitps, itps);
	}
	double change = 0.0;
	for (auto itp : itps) {
		int i = itp.first;
		int j = itp.second;
		double bef = pd2[i][j];
		pd2[i][j] = pd[i][j].b;
		for (auto sv : pd[i][j].a) {
			int as = sv.first;
			double v = sv.second;
			int ai = as / n;
			int aj = as % n;
			pd2[i][j] += v * pd2[ai][aj];
		}
		d_change[i][j] += abs(pd2[i][j] - bef);
		change += abs(pd2[i][j] - bef);
	}
	//trace(change);
	return change;
}


void solve() {
	cin >> a >> b;
	if (a == b) exit(0);
	n = a.size();
	for (int i = 0; i < 4*n + 4; i++) rematch_pd[i] = -1;

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < n; j++) {
			d_change[i][j] = 0.0;
			itps.push_back({i, j});
			pd[i][j] = Prob(-1.0);
		}
	}

	Prob x = solve(0, 0);

	build();

	while (iterate() > 1e-5);

	cout << setprecision(3) << fixed << pd2[0][0] << endl;
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    while (true) solve();
    return 0;
}
