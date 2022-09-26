#include <bits/stdc++.h>
using namespace std;
 
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x << endl;
 
typedef long long ll;
 
const ll N = 1e6;
const ll INF = 1LL << 61;
const ll MOD = 1e9 + 7;
 
void solve() {
	int n;
	cin >> n;
	n++;
	vector<ll> a(n), b(n);
 
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
 
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
 
	ll cuts = 0;
 
	for (int i = n-1; i >= 0; i--) {
		ll need = b[i] - a[i];
		if (need <= 0) continue;
		if (i == 0) {
			cout << "-1\n";
			return;
		}
		cuts += (need+1) / 2;
		b[i-1] += (need+1) / 2;
	}
 
 
	cout << cuts << "\n";
 
}
 
signed main() {
	fastio;
	solve();
	return 0;
}
