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

int p1, p2;
ll t1, t2;
int h, s;
vector<ll> pd;

ll solve(int h) {
	if (h <= 0) return 0;
	if (pd[h] != -1) return pd[h];

	ll T1 = t1, T2 = t2;
	int H = h;

	ll res = T1 + solve(h - (p1 - s));
	res = min(res, T2 + solve(h - (p2 - s)));

	H -= (p1 + p2 - s);
	res = min(res, max(T1, T2) + solve(H));

	while (H >= 0 && T1 != T2) {
		if (T1 < T2) {
			T1 += t1;
			H -= p1 - s;
		} else {
			T2 += t2;
			H -= p2 - s;
		}

		res = min(res, max(T1, T2) + solve(H));
	}

	return pd[h] = res;
}

void solve() {
	cin >> p1 >> t1;
	cin >> p2 >> t2;
	cin >> h >> s;
	pd.assign(h+1, -1);
	cout << solve(h) << "\n";

}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
