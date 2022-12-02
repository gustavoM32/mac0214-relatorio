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
const ll MOD = 998244353;

bool isPrime(ll n) {
	for (ll i = 2; i*i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void solve() {
	ll n, m;
	cin >> n >> m;

	ll res = 0;
	ll ways_all = 1;
	ll ways_unamb = 1;

	vector<ll> v = {1};

	for (ll i = 2; v.size() < n && v.back() <= m; i++) {
		if (isPrime(i)) v.push_back(v.back() * i);
		else v.push_back(v.back());
	}

	for (int i = 0; i < n; i++) {
		if (i < v.size()) {
			ways_unamb = ways_unamb * (m / v[i] % MOD) % MOD;
		} else ways_unamb = 0;

		ways_all = ways_all * (m % MOD) % MOD;
		res = (res + (ways_all + MOD - ways_unamb) % MOD) % MOD;
	}

	cout << res << "\n";

}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
