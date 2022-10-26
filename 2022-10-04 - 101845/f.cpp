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

struct dinic {
	ll n, s, t;
	vector<ll> dist, q, work;
	struct edge {
		ll to, rev, f, cap;
	};
	vector<vector<edge>> g;
	dinic(int n, int s, int t) : n(n), s(s), t(t), g(n), dist(n), q(n), work(n) {}
	void addEdge(int u, int v, ll cap) {
		g[u].pb((edge){v, sz(g[v]), 0, cap});
		g[v].pb((edge){u, sz(g[u]) - 1, 0, 0});
	}
	bool bfs() {
		for (int i = 0; i < n; i++) dist[i] = -1;
		dist[s] = 0;
		int qt = 0;
		q[qt++] = s;
		for (int qh = 0; qh < qt; qh++) {
			int u = q[qh];
			for (int i = 0; i < sz(g[u]); i++) {
				edge &e = g[u][i];
				int v=  g[u][i].to;
				if (dist[v] < 0 && e.f < e.cap) {
					dist[v] = dist[u] + 1;
					q[qt++]=v;
				}
			}
		}
		return dist[t] >= 0;
	}
	ll dfs(int u, ll f) {
		if (u == t) return f;
		for (ll &i = work[u]; i < sz(g[u]); i++) {
			edge &e = g[u][i];
			if (e.cap <= e.f) continue;
			int v = e.to;
			if (dist[v] == dist[u] + 1) {
				ll df = dfs(v, min(f, e.cap - e.f));
				if (df > 0) {
					e.f += df;
					g[v][e.rev].f -= df;
					return df;
				}
			}
		}
		return 0;
	}

	ll getFlow() {
		ll res = 0;
		while (bfs()) {
			for (int i = 0; i < n; i++) work[i] = 0;
			while (ll delta = dfs(s, INF)) res += delta;
		}
		return res;
	}
};

void solve() {
	int n;
	cin >> n;
	int c = 26;
	int s = n+c;
	int t = n+c+1;
	dinic d(n+c+2, s, t);
	for (int i = 0; i < n; i++) {
		vector<int> teams(c, 0);
		int mt = 0;
		for (int j = 0; j < 3; j++) {
			string s;
			cin >> s;
			for (char c : s) {
				teams[c-'A']++;
				mt = max(mt, teams[c-'A']);
			}
		}
		for (int j = 0; j < c; j++) {
			if (teams[j] == mt) {
				d.addEdge(i, n+j, 1);
			}
		}
	}
	int k;
	cin >> k;

	for (int i = 0; i < n; i++) {
		d.addEdge(s, i, 1);
	}
	for (int i = 0; i < c; i++) {
		d.addEdge(n+i, t, k);
	}

	cout << d.getFlow() << "\n";
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
