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

bool solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0, c = 0;
	int x, y, z;

	vector<int> bs;
	vector<int> cs;

	for (int i = 0; i < 2*n; i++) {
		char k = s[i];
		if (k == 'A') a++;
		else if (k == 'B') {
			bs.push_back(i);
			b++;
		} else {
			cs.push_back(i);
			c++;
		}
	}

	x = (a + b - c) / 2;
	y = (a + c - b) / 2;
	z = (b + c - a) / 2;
	if (x < 0 || y < 0 || z < 0) return false;

	vector<pair<int, int>> res;

	// match bc
	
	int bi = 0, ci = 0;
	while (z > 0 && bi < bs.size()) {
		if (ci == cs.size()) return false;
		int i = bs[bi];
		int j = cs[ci];
		if (i > j) ci++;
		else {
			res.push_back({i, j});
			s[i] = 'x';
			s[j] = 'x';
			z--;
			bi++;
			ci++;
		}
	}

	vector<int> bcs;

	for (int i = 0; i < 2*n; i++) {
		if (s[i] == 'B' || s[i] == 'C') {
			bcs.push_back(i);
		}
	}

	int bci = 0;

	// match ax
	for (int i = 0; i < 2*n; i++) {
		if (s[i] == 'x') continue;
		if (s[i] == 'A') {
			if (bci == bcs.size()) return false;
			int j = bcs[bci];
			if (i > j) return false;
			if (s[j] == 'B') {
				if (x == 0) return false;
				x--;
			} else {
				if (y == 0) return false;
				y--;
			}
			res.push_back({i, j});
			s[i] = 'x';
			s[j] = 'x';
			bci++;
		} else return false;
	}

	if (bci != bcs.size()) return false;

	cout << "YES\n";
	for (auto p : res) {
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	}

	return true;
}

signed main() {
	fastio;
	if (!solve()) {
		cout << "NO\n";
	}
	return 0;
}

