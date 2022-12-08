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

ll h;

vector<int> g;

int find(int i) {
	if (g[i] == i) return i;
	return g[i] = find(g[i]);
}

int uni(int r, int i, int j, vector<vector<int>> &tab) {
	ll d = (tab[r][j] + h - tab[r][i]) % h;

	i = find(i);
	j = find(j);
	if (i == j) return 0;

	int n = tab.size();

	for (int k = 0; k < n; k++) {
		if (tab[k][j] == -1) continue;

		if (tab[k][i] == -1) {
			tab[k][i] = (tab[k][j] + h - d) % h;
			continue;
		}

		if ((tab[k][j] + h - tab[k][i]) % h != d) return -1;
	}

	g[j] = i;
	return 1;
}

using pii = pair<int, int>;

int cnt(int n, int m, vector<vector<int>> &tab) {
	int cg = m;
	int er = 0;
	g.resize(m);

	for (int j = 0; j < m; j++) {
		g[j] = j;
	}

	int ner = -1;

	for (int i = 0; i < n; i++) {
		int f = -1;
		for (int j = 0; j < m; j++) {
			if (tab[i][j] == -1) continue;
			if (f != -1) {
				int unir = uni(i, f, j, tab);
				if (unir == -1) return -1;
				if (unir == 1) cg--;
			} else f = j;
		}
		if (f == -1) er++;
		else ner = i;
	}

	
	if (ner != -1) {
		int g = find(0);
		if (tab[ner][g] == -1) tab[ner][g] = 0;
		for (int j = 0; j < m; j++) {
			int gj = find(j);
			if (g == gj) continue;
			
			if (tab[ner][gj] == -1) tab[ner][gj] = 0;
			if (uni(ner, g, gj, tab) != 1) return -1;
		}
	}
	
	return cg-1+er;
}

void solve() {
	int n, m;
	cin >> n >> m;
	cin >> h;

	vector<vector<int>> tab(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tab[i][j];
		}
	}

	int res = cnt(n, m, tab);

	if (res == -1) {
		cout << "0\n";
		return;
	}

	ll r = 1;
	for (int i = 0; i < res; i++) {
		r = (r * h) % MOD;
	}

	cout << r << "\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
