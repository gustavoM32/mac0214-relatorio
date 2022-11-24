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
const ll INF = 2 * 1e9;
const ll MOD = 1e9 + 7;

void solve()
{
    int m;
    cin >> m;

    vector<vector<ll>> tab(2, vector<ll>(m));
    vector<vector<ll>> pd(2, vector<ll>(m + 1, -INF));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> tab[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            pd[i][j] = max(pd[i][j + 1] - 1, max(tab[i][j], tab[i ^ 1][j] - (2 * (m - j) - 1)));
        }
    }

    ll x = tab[0][0] - 1;
    ll res = INF;

    for (int j = 0; j < m; j++)
    {
        int r = j & 1;
        res = min(res, max(x, max(pd[r][j + 1] - 2 * j - 1, tab[r ^ 1][j] - 2 * m + 1)));
        x = max(x, tab[r ^ 1][j] - 2 * j - 1);
        res = min(res, max(x, pd[r ^ 1][j + 1] - 2 * j - 2));

        if (j < m - 1)
        {
            x = max(x, tab[r ^ 1][j + 1] - 2 * j - 2);
        }
    }

    cout << res + 2 * m << "\n";
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
