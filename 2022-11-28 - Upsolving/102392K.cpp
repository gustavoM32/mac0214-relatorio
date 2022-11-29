// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 505;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

struct Pos {
	int k, i, j;

	Pos() {}
	Pos(int k, int i, int j) : k(k), i(i), j(j) {}

	string toString() {
		stringstream ss;
		ss << "(" << setw(2) << k << ", " << setw(2) << i << ", " << setw(2) << j << ")";
		return ss.str();
	}
};

bool operator<(const Pos &a, const Pos &b) {
	return array<int, 3>({a.k, a.i, a.j}) < array<int, 3>({b.k, b.i, b.j});
}

bool operator==(const Pos &a, const Pos &b) {
	return a.i == b.i && a.j == b.j && a.k == b.k;
}

//   +---+
//  / 0 /|
// +---+2+
// | 1 |/
// +---+

struct Tab {
	int p, n, m;
	string tab[N][N];

	Tab() {}
	Tab(int p, int n, int m) : p(p), n(n), m(m) {}

	int getDim(int order, int d = 0) {
		array<int, 3> dims = {p, n, m};

		switch (d) {
			case 1:
			case 4:
				swap(dims[1], dims[0]);
				break;
			case 2:
			case 5:
				swap(dims[2], dims[0]);
				break;
		}

		return dims[order];

	}

	Pos toActualPos(Pos pos, int d=0) {
		int k = pos.k;
		int i = pos.i;
		int j = pos.j;

		switch (d) {
			case 1:
				k = getDim(0, d)-1 - k;
				swap(i, k);
				break;
			case 2:
				k = getDim(0, d)-1 - k;
				swap(j, k);
				break;
			case 3:
				k = getDim(0, d)-1 - k;
				i = getDim(1, d)-1 - i;
				break;
			case 4:
				i = getDim(1, d)-1 - i;
				swap(i, k);
				break;
			case 5:
				j = getDim(2, d)-1 - j;
				swap(j, k);
				break;
		}

		return Pos(k, i, j);
	}

	char get(int k, int i, int j, int d=0) {
		Pos p = toActualPos(Pos(k, i, j), d);

		return tab[p.k][p.i][p.j];
	}

	void pprint(int d=0) {
		cout << "  +---+\n";
		cout << " / " << get(0, 1, 1, d) << " /|\n";
		cout << "+---+" << get(1, 1, 2, d) << "+\n"; 
		cout << "| " << get(1, 2, 1, d) << " |/\n";
		cout << "+---+\n";
	}

	void print(int d=0) {
		for (int k = 0; k < getDim(0, d); k++) {
			for (int i = 0; i < getDim(1, d); i++) {
				for (int j = 0; j < getDim(2, d); j++) {
					cout << get(k, i, j, d);
				}
				cout << "\n";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
};

Pos r, t;

void readTab(Tab &tab) {
	cin >> tab.m >> tab.n >> tab.p;

	for (int k = 0; k < tab.p; k++) {
		for (int i = 0; i < tab.n; i++) {
			cin >> tab.tab[k][i];
			for (int j = 0; j < tab.m; j++) {
				char c = tab.tab[k][i][j];
				if (c == 'R') r = Pos(k, i, j);
				else if (c == 'T') t = Pos(k, i, j);
			}
		}
	}
}

map<Pos, set<Pos>> adjs;

void getAdjs(Tab &tab, int d) {
	set<Pos> lit;
	vector<vector<vector<int>>> fall(tab.getDim(0, d),
			vector<vector<int>>(tab.getDim(1, d),
				vector<int>(tab.getDim(2, d), -1)));

	for (int i = 0; i < tab.getDim(1, d); i++) {
		for (int j = 0; j < tab.getDim(2, d); j++) {
			int lastK = -1;
			for (int k = tab.getDim(0, d) - 1; k >= 0; k--) {
				char c = tab.get(k, i, j, d);
				if (c == '*') {
					lastK = k;
				}
				fall[k][i][j] = lastK;
			}
		}
	}

	for (int i = 0; i < tab.getDim(1, d); i++) {
		for (int j = 0; j < tab.getDim(2, d); j++) {
			if (fall[0][i][j] != -1) lit.insert(Pos(fall[0][i][j], i, j));
		}
	}

	for (int k = 0; k < tab.getDim(0, d); k++) {
		for (int i = 0; i < tab.getDim(1, d); i++) {
			for (int j = 0; j < tab.getDim(2, d); j++) {
				if (tab.get(k, i, j, d) == '*') continue;
				// pos not lit
				if (lit.find(Pos(fall[k][i][j], i, j)) == lit.end()) continue;

				Pos orig = tab.toActualPos(Pos(k, i, j), d);
				bool attached = false;
				bool floor = false;

				for (int h = 0; h < 6; h++) {
					int ak = k + int(h == 0) - int(h == 1);
					int ai = i + int(h == 2) - int(h == 3);
					int aj = j + int(h == 4) - int(h == 5);
					if (ak < 0 || ak >= tab.getDim(0, d)) continue;
					if (ai < 0 || ai >= tab.getDim(1, d)) continue;
					if (aj < 0 || aj >= tab.getDim(2, d)) continue;

					if (tab.get(ak, ai, aj, d) == '*') {
						attached = true;
						if (h == 0) floor = true;
						break;
					}
				}

				// If there is a cell below
				if (floor) {
					for (int h = 0; h < 4; h++) {
						int ai = i + int(h == 0) - int(h == 1);
						int aj = j + int(h == 2) - int(h == 3);
						if (ai < 0 || ai >= tab.getDim(1, d)) continue;
						if (aj < 0 || aj >= tab.getDim(2, d)) continue;
						int fallsK = fall[k][ai][aj];
						Pos falls = Pos(fall[k][ai][aj], ai, aj);
						if (fallsK == -1 || fallsK == k || lit.find(falls) == lit.end()) continue;
						// Across the floor
						// Jumping off a cliff
						falls.k--;
						Pos dest = tab.toActualPos(falls, d);
						adjs[orig].insert(dest);
					}
				} else if (attached) {
					// Dropping down
					int fallsK = fall[k][i][j];
					Pos falls = Pos(fall[k][i][j], i, j);
					if (!(fallsK == -1 || fallsK == k || lit.find(falls) == lit.end())) {
						falls.k--;
						Pos dest = tab.toActualPos(falls, d);
						adjs[orig].insert(dest);
					}
				}
			}
		}
	}
}

map<Pos, int> dist;

int bfs() {
	queue<Pos> q;
	dist[r] = 0;
	q.push(r);

	while (!q.empty()) {
		Pos v = q.front();
		int d = dist[v];
		if (v == t) return d;
		q.pop();

		for (Pos a : adjs[v]) {
			if (dist.find(a) == dist.end()) {
				dist[a] = d + 1;
				q.push(a);
			}
		}
	}

	return -1;
}

void getAdjs() {
	Tab tab;
	readTab(tab);

	for (int d = 0; d < 6; d++) {
		getAdjs(tab, d);
	}
}

void solve() {
	getAdjs();
	cout << bfs() << "\n";
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
