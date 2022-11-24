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
    map<char, char> mp;
    string f, s;
    cin >> f >> s;
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == s[i])
            continue;
        if (mp.find(f[i]) != mp.end())
        {
            if (mp[f[i]] != s[i])
            {
                cout << "-1\n";
                return;
            }
        }
        else
        {
            if (mp.find(s[i]) != mp.end())
            {
                cout << "-1\n";
                return;
            }

            mp[f[i]] = s[i];
            mp[s[i]] = f[i];
        }
    }

    for (int i = 0; i < f.size(); i++)
    {
        if (mp.find(f[i]) != mp.end() && mp[f[i]] != s[i])
        {
            cout << "-1\n";
            return;
        }
    }

    cout << mp.size() / 2 << "\n";
    set<char> printed;
    for (auto p : mp)
    {
        if (printed.find(p.first) != printed.end())
            continue;
        printed.insert(p.second);
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