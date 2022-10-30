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

vector<set<int>> in, out;
vector<int> h;

void calc(int u) {
	h[u] = 0;
	for (int v : out[u]) {
		if (h[v] == -1) calc(v);
		h[u] = max(h[u], h[v] + 1);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	in.resize(n);
	out.resize(n);
	h.assign(n, -1);

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		out[u].insert(v);
		in[v].insert(u);
	}

	for (int i = 0; i < n; i++) {
		if (out[i].size() == 1) {
			out[i].clear();
		}
	}
	for (int i = 0; i < n; i++) {
		if (in[i].size() == 1) {
			int u = *in[i].begin();
			if (out[u].find(i) != out[u].end()) out[u].erase(i);
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (h[i] == -1) calc(i);
		res = max(res, h[i] + 1);
	}
	cout << res << "\n";
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
