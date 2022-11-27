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
const ll MOD = 1e9 + 7;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), p(n);
    vector<int> o(n), b(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        o[p[i] - 1] = i;
    }

    int ci = -1000000100;

    for (int i : o)
    {
        ci = max(l - a[i], ci + 1);

        b[i] = ci + a[i];

        if (b[i] > r)
        {
            cout << "-1\n";
            return;
        }
    }

    for (int i : b)
        cout << i << " ";
    cout << "\n";
}

int main()
{
    FASTIO;
    // int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
