// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 1e2 + 10;
const ll INF = 1ll << 61;
const ll MOD = 998244353;

// constraints that end at j, const[type][j] = i
int consts[2][N];
ll pd[N][N];
int n;

// i = last different
ll solve(int i, int j) {
	if (pd[i][j] != -1) return pd[i][j];
	if (j == n) return pd[i][j] = 1;

	if (consts[0][j] != -1) {
		if (i > consts[0][j]) return pd[i][j] = 0;
		// should stay equal
		if (i <= consts[1][j]) {
			// should be different
			return pd[i][j] = 0;
		}
		return pd[i][j] = solve(i, j+1);
	}

	if (consts[1][j] != -1) {
		if (i <= consts[1][j]) {
			// should be different
			return pd[i][j] = solve(j, j+1);
		}
	}

	return pd[i][j] = (solve(i, j+1) + solve(j, j+1)) % MOD;
}

void solve() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		consts[0][i] = consts[1][i] = -1;
	}

	bool res = true;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int a;
			cin >> a;
			if (i == j) {
				if (a == 2) res = false;
				continue;
			}
			if (a == 2 || (a == 1 && consts[0][j] == -1))
				consts[a-1][j] = i;
		}
	}

	if (!res) {
		cout << "0\n";
		return;
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			pd[i][j] = -1;
		}
	}

	cout << solve(0, 0) << "\n";
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
