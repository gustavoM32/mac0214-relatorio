// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x << endl;

typedef long long ll;
const ll N = 1e6 + 10;
const ll INF = 1ll << 61;
const ll MOD = 998244353;

ll n, z;

ll modexp(ll b, ll e, ll m = MOD)
{
    ll res = 1;
    b %= m;
    while (e > 0)
    {
        if (e & 1)
            res = (res * b) % m;
        b = (b * b) % m;
        e /= 2;
    }
    return res;
}

ll inv(ll a, ll m = MOD)
{
    return modexp(a, m - 2, m);
}

ll solve(ll k)
{
    if (k == z)
        return 0;
    ll q = solve(k + 1);
    ll p = 2 * (z - k) * (z - k) % MOD * inv(n) % MOD * inv(n - 1) % MOD;
    return (1 + p * q % MOD) * inv(p) % MOD;
}

void solve()
{
    cin >> n;
    vector<int> a(n);
    z = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            z++;
    }
    int ac = 0;
    for (int i = 0; i < z; i++)
    {
        if (a[i] == 0)
            ac++;
    }
    cout << solve(ac) << "\n";
}

int main()
{
    FASTIO;
    int tst;
    cin >> tst;
    while (tst--)
        solve();
    return 0;
}
