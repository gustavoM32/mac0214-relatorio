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
	vector<int> v;
	for (int i = n-2; i >= 1; i--) v.push_back(i);
	v.push_back(n-1);
	v.push_back(n);

	if (n % 2 == 1) swap(v[0], v[1]);
	for (int i : v) cout << i << " ";
	cout << "\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
