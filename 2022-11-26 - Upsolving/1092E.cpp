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
const ll N = 1e3 + 10;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

int dist[N][2];
int par[N];
vector<int> adjs[N];

using pii = pair<int, int>;

int dfs(int v, int s)
{
    int d = v;

    for (int a : adjs[v])
    {
        if (a == par[v])
            continue;
        dist[a][s] = dist[v][s] + 1;
        par[a] = v;

        int da = dfs(a, s);

        if (dist[da][s] > dist[d][s])
        {
            d = da;
        }
    }

    return d;
}

pii getCenter(int v)
{
    dist[v][0] = 0;
    par[v] = -1;
    int a = dfs(v, 0);

    par[a] = -1;
    dist[a][1] = 0;
    int b = dfs(a, 1);

    int d = dist[b][1];

    for (int i = 0; i < d / 2; i++)
    {
        b = par[b];
    }

    // returns {diameter, center}
    return {d, b};
}

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }

    for (int i = 0; i < n; i++)
    {
        dist[i][0] = dist[i][1] = -1;
    }

    vector<pii> centers;

    for (int i = 0; i < n; i++)
    {
        if (dist[i][1] != -1)
            continue;

        centers.push_back(getCenter(i));
    }

    sort(centers.rbegin(), centers.rend());

    int fd = centers.front().first;
    int fc = centers.front().second;

    if (centers.size() == 1)
    {
        cout << fd << "\n";
    }
    else
    {
        for (int i = 1; i < centers.size(); i++)
        {
            int u = fc;
            int v = centers[i].second;
            adjs[u].push_back(v);
            adjs[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            dist[i][0] = dist[i][1] = -1;
        }

        cout << getCenter(0).first << "\n";

        for (int i = 1; i < centers.size(); i++)
        {
            cout << fc + 1 << " " << centers[i].second + 1 << "\n";
        }
    }
}

int main()
{
    FASTIO;
    // int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
