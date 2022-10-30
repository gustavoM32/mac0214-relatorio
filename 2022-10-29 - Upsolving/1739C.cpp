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

using ct = array<ll, 3>;
// 0 A
// 1 B
// 2 draw
vector<ll> fat;

ll modexp(ll b, ll e, ll m = MOD) {
	ll res = 1;
	b %= m;
	while (e > 0) {
		if (e & 1) res = (res * b) % m;
		b = (b * b) % m;
		e /= 2;
	}
	return res;
}

ll inv(ll a, ll m = MOD) {
	return modexp(a, m-2, m);
}

ll choose(ll n, ll p) {
	return (fat[n] * inv(fat[p]) % MOD) * inv(fat[n-p]) % MOD;
}

ct calc(int n) {
	if (n == 0) return {0, 0, 1};
	if (n == 2) return {1, 0, 1};
	ct res;
	res[0] = choose(n - 1, n/2 - 1);
	res[1] = choose(n - 2, n/2 - 2);
	res[2] = 0;

	ct n2 = calc(n-2);
	res[0] = (res[0] + n2[1]) % MOD;
	res[1] = (res[1] + n2[0]) % MOD;
	res[2] = n2[2];

	return res;
}

void solve() {
	int n;
	cin >> n;
	ct res = calc(n);
	cout << res[0] << " " << res[1] << " " << res[2] << "\n";
}

int main() {
	fat.resize(65);
	fat[0] = 1;
	for (int i = 1; i <= 60; i++) {
		fat[i] = fat[i-1] * i % MOD;
	}
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
