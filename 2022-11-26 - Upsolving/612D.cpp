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
const ll INF = -1000000010;
const ll MOD = 1e9 + 7;
using pii = pair<int, int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pii> ss;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        ss.push_back({l, -1});
        ss.push_back({r, 1});
    }

    sort(ss.begin(), ss.end());

    int ri = INF;
    int l = 0;
    int i = 0;

    vector<pii> res;

    while (i < 2 * n)
    {
        int p = ss[i].first;

        while (i < 2 * n && ss[i].first == p && ss[i].second == -1)
        {
            l++;
            i++;

            if (l >= k && ri == INF)
            {
                ri = p;
            }
        }

        while (i < 2 * n && ss[i].first == p && ss[i].second == 1)
        {
            l--;
            i++;

            if (l < k && ri != INF)
            {
                res.push_back({ri, p});
                ri = INF;
            }
        }
    }

    if (ri != INF)
    {
        res.push_back({ri, ss.back().first});
    }

    cout << res.size() << "\n";
    for (auto p : res)
    {
        cout << p.first << " " << p.second << "\n";
    }
}

int main()
{
    FASTIO;
    // int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
