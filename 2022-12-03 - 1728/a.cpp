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
	int y = 0;
	int r = -1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > y) {
			y = x;
			r = i;
		}
	}

	cout << r + 1 << "\n";

}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
