#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x << endl;

typedef long long ll;

const ll N = 1e6;
const ll INF = 1LL << 61;
const ll MOD = 1e9 + 7;

struct Prob {
	map<int, double> p;

	void print() {
		cout << "Probs: \n";
		for (auto el : p) {
			cout << el.first << ": " << el.second << "\n";
		}
		cout << endl;
	}
};

vector<Prob> solvePairs(vector<Prob> &v) {
	vector<Prob> r;
	for (int i = 0; 2*i < v.size(); i++) {
		Prob c;
		for (auto a : v[2*i].p) {
			int ar = a.first;
			double ap = a.second;
			for (auto b : v[2*i+1].p) {
				int br = b.first;
				double bp = b.second;
				c.p[ar] += double(abs(ar)) / (abs(ar) + abs(br)) * ap * bp;
				c.p[br] += double(abs(br)) / (abs(ar) + abs(br)) * ap * bp;
			}
		}
		r.push_back(c);
	}

	return r;
}

vector<Prob> solve(vector<Prob> &v) {
	int p = 1;
	while (p < v.size()) p <<= 1;
	if (p == v.size()) return solvePairs(v);
	p >>= 1;
	int excess = int(v.size()) - p;
	vector<Prob> s;
	for (int i = 0; i < 2*excess; i++) {
		s.push_back(v[i]);
	}
	s = solvePairs(s);
	for (int i = 2*excess; i < v.size(); i++) {
		s.push_back(v[i]);
	}
	return solvePairs(s);
}

void solve() {
	int n;
	cin >> n;
	vector<Prob> v(n);

	int f;
	cin >> f;

	vector<int> r(n-1);

	for (int i = 0; i < n-1; i++) {
		cin >> r[i];
	}

	sort(r.rbegin(), r.rend());

	for (int i = 0; i < n-1; i++) {
		v[i].p[r[i]] = 1.0;
	}

	v[n-1].p[-f] = 1.0;

	while (v.size() > 1) {
		v = solve(v);
	}
	
	cout << setprecision(15) << fixed << v[0].p[-f] << "\n";
}

signed main() {
	fastio;
	solve();
	return 0;
}

