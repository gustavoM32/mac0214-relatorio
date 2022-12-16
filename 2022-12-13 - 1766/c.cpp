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

void solve() {
	int m;
	cin >> m;
	array<string, 2> tab;
	cin >> tab[0] >> tab[1];
	int l = 2;

	for (int i = 0; i < m; i++) {
		if (tab[0][i] == tab[1][i]) {// both black
			if (l != 2) {
				l = 1 - l;
			}
		} else if (tab[0][i] == 'B') {
			if (l == 1) {
				cout << "NO\n";
				return;
			}

			if (l == 2) {
				l = 0;
			}
		} else {
			if (l == 0) {
				cout << "NO\n";
				return;
			}

			if (l == 2) {
				l = 1;
			}
		}
	}

	cout << "YES\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
