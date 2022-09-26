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
	int n;
	cin >> n;
	vector<ll> x(n), t(n);

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}

	ll X = -INF, Y = -INF;

	for (int i = 0; i < n; i++) {
		X = max(X, t[i] + x[i]);
		Y = max(Y, t[i] - x[i]);
	}

	cout << setprecision(7) << fixed << (X - Y) / 2.0 << "\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
