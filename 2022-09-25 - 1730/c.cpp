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

int getmin(map<int, int> &m) {
	for (int i = 0; i < 10; i++) {
		if (m.find(i) != m.end() && m[i] > 0) return i;

	}

	return 10;
}

void print(map<int, int>&m) {
	cout << endl;
	for (auto p : m) {
		cout << p.first << ": " << p.second << endl;
	}
	cout << endl;
}

void solve() {
	string s;
	cin >> s;
	map<int, int> flut;
	map<int, int> rem;
	int n = s.size();

	for (char c : s) rem[c-'0']++;

	string res;
	int i = 0;
	while (i < n) {
		int mf = getmin(flut);
		int mr = getmin(rem);


		if (mf <= mr) {
			res += ('0' + mf);
			flut[mf]--;
		} else {
			while (s[i] - '0' != mr) {
				int ds = s[i] - '0';
				flut[min(ds+1, 9)]++;
				rem[s[i]-'0']--;
				i++;
			}
			res += ('0' + mr);
			rem[mr]--;
			i++;
		}
	}

	int mf;
	while ((mf = getmin(flut)) != 10) {
		res += ('0' + mf);
		flut[mf]--;
	}

	cout << res << "\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
