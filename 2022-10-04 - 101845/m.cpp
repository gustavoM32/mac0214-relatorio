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
	ll n, m, k;
	cin >> n >> m >> k;
	double res = 0.0;
	if (m <= k-1) {
		res = double(m) / k;
	} else {
		ll rm = m - (k-1);
		res = double(k-1)/k;
		res += 1.0 / k * (double(rm) / (n + rm));
	}
	cout << setprecision(9) << fixed << res << "\n";
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
