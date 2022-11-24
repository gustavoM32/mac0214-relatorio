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

int solve(array<int, 3> x, array<int, 3> y)
{
    if (x[0] == x[1] && x[1] == x[2])
    {
        return 1;
    }

    if (x[0] == x[2])
    {
        swap(x[1], x[2]);
        swap(y[1], y[2]);
    }
    else if (x[1] == x[2])
    {
        swap(x[0], x[2]);
        swap(y[0], y[2]);
    }

    if (x[0] == x[1])
    {
        int ly = min(y[0], y[1]);
        int uy = max(y[0], y[1]);
        if (y[2] <= ly)
            return 2;
        if (y[2] >= uy)
            return 2;
    }

    return 3;
}

void solve()
{
    array<int, 3> x, y;
    for (int i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }

    cout << min(solve(x, y), solve(y, x)) << "\n";
}

int main()
{
    FASTIO;
    // int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
