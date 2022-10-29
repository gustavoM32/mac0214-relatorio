// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 2e5 + 10;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

int n, k;
using pii = pair<int, int>;

int p[N];
int h[N];
int removed[N];
vector<int> adjs[N];
set<pii> hs;


void calc_h(int v) {
	for (int a : adjs[v]) {
		if (a != p[a]) {
			h[a] = h[v] + 1;
			calc_h(a);
		}
	}
}

void explore(int v) {
	if (removed[v]) return;
	hs.erase({h[v], v});
	removed[v] = true;
	for (int a : adjs[v]) {
		if (a != p[a]) explore(a);
	}
}

bool bb(int m) {
	hs.clear();
	for (int i = 0; i < n; i++) {
		hs.insert({h[i], i});
		removed[i] = false;
	}

	int kk = k;

	while (!hs.empty() && kk > 0) {
		int i = hs.rbegin()->second;
		int mm = m-1;
		while (mm > 0 && i != 0) {
			i = p[i];
			mm--;
		}
		explore(i);
		kk--;
	}

	return hs.empty() || hs.rbegin()->first <= m;
}

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) adjs[i].clear();
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		p[i]--;
		adjs[p[i]].push_back(i);
	}

	h[0] = 0;
	calc_h(0);

	int l = 1, r = n-1;
	while (l < r) {
		int m = (l + r) / 2;
		if (bb(m)) r = m;
		else l = m+1;
	}
	cout << l << "\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
		solve();
    return 0;
}
