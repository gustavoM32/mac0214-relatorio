// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 1e7 + 10;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

int fac[N];

void solve() {
	ll x, y;
	cin >> x >> y;
	ll d = y - x;
	ll res = INF;

	while (d > 1) {
		int i = fac[d];
		if (x % i == 0) res = 0;
		res = min(res, i - x % i);
		d /= i;
	}

	if (res == INF) cout << "-1\n";
	else cout << res << "\n";
}

int main() {
    FASTIO;
	for (int i = 0; i < N; i++) {
		fac[i] = -1;
	}

	for (int p = 2; p < N; p++) {
		if (fac[p] != -1) continue;
		for (int m = p; m < N; m += p) {
			if (fac[m] == -1)
				fac[m] = p;
		}
	}

    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
