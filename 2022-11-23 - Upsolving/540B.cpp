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
const ll INF = 1l << 61;
const ll MOD = 1e9 + 7;

void solve()
{
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector<int> v;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        int g;
        cin >> g;
        sum += g;
        if (g < y)
            cnt++;
    }

    if (cnt > n / 2)
    {
        cout << "-1\n";
        return;
    }

    while (cnt < n / 2 && k + v.size() < n)
    {
        sum++;
        cnt++;
        v.push_back(1);
    }

    while (k + v.size() < n)
    {
        sum += y;
        v.push_back(y);
    }

    if (sum > x)
    {
        cout << "-1\n";
        return;
    }

    for (int i : v)
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
