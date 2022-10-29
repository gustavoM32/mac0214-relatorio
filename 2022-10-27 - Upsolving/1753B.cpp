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

bool solve() {
	int n, x;
	cin >> n >> x;
	vector<int> c(x+1, 0);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (int i = 0; i < x; i++) {
		if (c[i] % (i+1) != 0) return false;
		c[i+1] += c[i] / (i+1);
	}

	return true;
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    cout << (solve() ? "Yes\n" : "No\n");
    return 0;
}
