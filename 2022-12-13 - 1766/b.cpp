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
	set<string> occ;
	string old;
	for (int i = 1; i < n; i++) {
		string p = s.substr(i-1, 2);
		if (occ.find(p) != occ.end()) {
			cout << "YES\n";
			return;
		}
		if (i != 1) occ.insert(old);
		old = p;
	}
	cout << "NO\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
