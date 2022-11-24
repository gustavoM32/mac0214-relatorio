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

int count(int x, int y1, int y2)
{
    if (abs(y1 - x) & 1)
        y1++;
    if (abs(y2 - x) & 1)
        y2--;
    return (y2 - y1) / 2 + 1;
}

void solve()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    x2 -= x1;
    y2 -= y1;
    x1 = 0;
    y1 = 0;

    ll f = count(x1, y1, y2);
    ll s = count(x1 + 1, y1, y2);
    trace(f);
    trace(s);
    ll cf = (x2 - x1 + 1) / 2 + 1;

    cout << cf * f + (cf - 1) * s << "\n";
}

int main()
{
    FASTIO;
    // int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
