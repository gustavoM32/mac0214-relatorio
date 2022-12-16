// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 1e5 + 10;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

ll pd[N][11][3];
vector<int> adjs[N];
ll m, k;

ll solve2(int v, int x, int t, int p=-1);

// ways to have exactly x highest security vaults among the subtrees formed by the adjacent vertices of v starting from the i-th one and the type of v is t
ll solve1(int v, int x, int t, int i, int p=-1) {
	if (i == adjs[v].size()) return x == 0;
	if (adjs[v][i] == p) return solve1(v, x, t, i+1, p);
	
	ll res = 0;
	int a = adjs[v][i];

	for (int y = 0; y <= x; y++) {
		ll ast = (k - 1) * solve2(a, y, 0, v) % MOD;

		if (t != 1) {
			ast = (ast + (m - k) * solve2(a, y, 2, v) % MOD) % MOD;

			if (t == 0 && y > 0) {
				ast = (ast + solve2(a, y-1, 1, v)) % MOD;
			}
		}

		res = (res + solve1(v, x-y, t, i+1, p) * ast % MOD) % MOD;
	}

	return res;
}

// ways to have exactly x highest security vaults in the subtree defined by v if the type of v is t
ll solve2(int v, int x, int t, int p) {
	// BASE
	if (pd[v][x][t] != -1) return pd[v][x][t];
	return pd[v][x][t] = solve1(v, x, t, 0, p); 
}

void solve() {
	int n, x;
	cin >> n >> m;

	for (int i = 0; i < n-1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adjs[u].push_back(v);
		adjs[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 11; j++) {
			pd[i][j][0] = pd[i][j][1] = pd[i][j][2] = -1;
		}
	}

	cin >> k >> x;

	ll cc = 0;

	for (ll y = 0; y <= x; y++) {
		ll res = (k - 1) * solve2(0, y, 0) % MOD;
		if (y > 0)
			res = (res + solve2(0, y-1, 1)) % MOD;
		res = (res + (m - k) * solve2(0, y, 2) % MOD) % MOD;
		cc = (cc + res) % MOD;
	}

	cout << cc << "\n";
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}