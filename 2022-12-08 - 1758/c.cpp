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
	ll n, x;
	cin >> n >> x;
	if (n % x != 0) {
		cout << "-1\n";
		return;
	}

	vector<int> v;

	queue<int> f;

	ll nn = n / x;

	for (ll p = 2; p*p <= nn; p++) {
		while (nn % p == 0) {
			f.push(p);
			nn /= p;
		}
	}

	if (nn > 1) f.push(nn);

	v.push_back(x);
	
	for (ll i = 2; i < n; i++) {
		if (!f.empty() && i == x) {
			ll nx = x * f.front();
			f.pop();
			v.push_back(nx);
			x = nx;
		} else {
			v.push_back(i);
		}
	}

	v.push_back(1);
	
	for (ll el : v) cout << el << " ";
	cout << "\n";


}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
