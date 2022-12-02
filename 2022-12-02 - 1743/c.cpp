// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 1e6 + 10;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	ll res = 0;

	int i = 0;
	while (i < n) {
		if (s[i] == '1') {
			ll v0 = i > 0 ? v[i-1] : 0;
			res += v0;
			ll segmin = v0;

			while (i < n && s[i] == '1') {
				res += v[i];
				segmin = min(segmin, ll(v[i]));
				i++;
			}

			res -= segmin;
		}
		i++;
	}

	cout << res << "\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
