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
using pii = pair<int, int>;
using pipii = pair<ll, pii>;

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

ll tab[N][N];
pii gs[N][N];
ll gss[N][N];
ll cs[N][N];
int n, m;

pii find(pii c)
{
    int i = c.first;
    int j = c.second;

    if (gs[i][j] == c)
        return c;
    return gs[i][j] = find(gs[i][j]);
}

void uni(pii a, pii b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;

    int ai = a.first;
    int aj = a.second;
    int bi = b.first;
    int bj = b.second;

    gs[ai][aj] = gs[bi][bj];
    gss[bi][bj] += gss[ai][aj];
}

void add(pii c)
{
    int i = c.first;
    int j = c.second;

    for (int k = 0; k < 4; k++)
    {
        int ai = i + di[k];
        int aj = j + dj[k];

        if (ai < 0 || ai >= n)
            continue;
        if (aj < 0 || aj >= m)
            continue;

        if (tab[ai][aj] >= tab[i][j])
        {
            uni(c, {ai, aj});
        }
    }
}

void persist(pii c)
{
    int i = c.first;
    int j = c.second;
    c = find(c);
    int gi = c.first;
    int gj = c.second;

    cs[i][j] = gss[gi][gj];
}

ll k;

void dfs(pii c, ll h)
{
    int i = c.first;
    int j = c.second;
    tab[i][j] = -1;
    k -= h;

    for (int kk = 0; kk < 4; kk++)
    {
        int ai = i + di[kk];
        int aj = j + dj[kk];

        if (ai < 0 || ai >= n)
            continue;
        if (aj < 0 || aj >= m)
            continue;

        if (tab[ai][aj] < h)
            continue;
        if (k == 0)
            continue;

        dfs({ai, aj}, h);
    }
}

void solve(pii c, ll h)
{
    dfs(c, h);

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (tab[i][j] == -1)
                cout << h << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}

void solve()
{
    cin >> n >> m >> k;

    vector<pipii> cells;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            gs[i][j] = {i, j};
            gss[i][j] = 1;
            cin >> tab[i][j];
            cells.push_back({tab[i][j], {i, j}});
        }
    }

    sort(cells.rbegin(), cells.rend());

    // get for each cell the number of connected cells that are greater or equal to the cell value
    int s = 0;
    while (s < n * m)
    {
        int e = s;

        while (e < n * m && cells[e].first == cells[s].first)
        {
            add(cells[e].second);
            e++;
        }

        for (int i = s; i < e; i++)
        {
            persist(cells[i].second);
        }

        s = e;
    }

    // then iterate over the candidate heights, discard if the height does not divide k and check if the number of needs cells is smaller or equal to the calculated value

    for (auto cp : cells)
    {
        ll h = cp.first;
        pii c = cp.second;

        if (k % h != 0)
            continue;

        ll num = k / h;

        if (cs[c.first][c.second] >= num)
        {
            solve(c, h);
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    FASTIO;
    // int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
