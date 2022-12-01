// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 500;
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

	int getDim(int order, int d) {
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

	Pos toActualPos(Pos pos, int d) {
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

	char get(int k, int i, int j, int d) {
		Pos p = toActualPos(Pos(k, i, j), d);

		return tab[p.k][p.i][p.j];
	}

	void set(int k, int i, int j, char c, int d) {
		Pos p = toActualPos(Pos(k, i, j), d);

		tab[p.k][p.i][p.j] = c;
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
int pp, mm, nn;

void readTab(Tab &tab) {
	scanf("%d %d %d", &tab.m, &tab.n, &tab.p);
	pp = tab.p;
	nn = tab.n;
	mm = tab.m;
	char c[N];

	for (int k = 0; k < tab.p; k++) {
		for (int i = 0; i < tab.n; i++) {
			scanf("%s", c);
			tab.tab[k][i] = string(c);
			for (int j = 0; j < tab.m; j++) {
				char c = tab.tab[k][i][j];
				if (c == 'R') r = Pos(k, i, j);
				else if (c == 'T') t = Pos(k, i, j);
			}
		}
	}
}

void litTab(Tab &tab, int d) {
	int p = tab.getDim(0, d);
	int n = tab.getDim(1, d);
	int m = tab.getDim(2, d);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < p; k++) {
				if (tab.get(k, i, j, d) == '*') {
					if (k > 0) tab.set(k-1, i, j, '+', d);
					break;
				}
			}
		}
	}
}

void litTab(Tab &tab) {
	for (int d = 0; d < 6; d++) litTab(tab, d);
}

unordered_map<int, vector<int>> adjs;

using chrono::duration_cast;
using chrono::nanoseconds;
using chrono::seconds;
using chrono::system_clock;

ll getMillis() {
    return duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
}

inline int getCd(int k, int i, int j) {
	return nn*mm*k + mm*i + j;
}

inline int getCd(Pos p) {
	return getCd(p.k, p.i, p.j);
}

void getAdjs(Tab &tab, int d) {
	int p = tab.getDim(0, d);
	int n = tab.getDim(1, d);
	int m = tab.getDim(2, d);

	vector<vector<int>> lit(n, vector<int>(m, -1));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k = 0;
			while (k < p && tab.get(k, i, j, d) != '*') k++;
			if (k == p) k = 0;
			lit[i][j] = k-1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int k = lit[i][j];
			if (k == -1) continue;
			int thisPos = getCd(tab.toActualPos(Pos(k, i, j), d));

			// Add this as origin for adjacent positions
			for (int h = 0; h < 4; h++) {
				int ai = i + int(h == 0) - int(h == 1);
				int aj = j + int(h == 2) - int(h == 3);
				if (ai < 0 || ai >= n) continue;
				if (aj < 0 || aj >= m) continue;

				int ak = lit[ai][aj];

				// Across the floor
				// Jumping off a cliff
				if (k <= ak) {
					int dest = getCd(tab.toActualPos(Pos(ak, ai, aj), d));
					if (adjs.find(thisPos) == adjs.end()) adjs[thisPos].reserve(6);
					adjs[thisPos].push_back(dest);
				}
			}

			// Add origins that have this block as a destination when the move is only falling
			for (int ak = k-1; ak >= 0; ak--) {
				if (tab.get(ak, i, j, d) != '+') continue; // ignore positions that are unlit or unattached in every direction
				int orig = getCd(tab.toActualPos(Pos(ak, i, j), d));
				adjs[orig].push_back(thisPos);
				if (adjs.find(orig) == adjs.end()) adjs[orig].reserve(6);
			}

		}
	}
}

int bfs() {
	int rr = getCd(r);
	int tt = getCd(t);
	string vis;
	vis.resize(pp*nn*mm);
	queue<pair<int, int>> q;
	vis[rr] = 1;
	q.push({rr, 0});

	while (!q.empty()) {
		int v = q.front().first;
		int d = q.front().second;
		if (v == tt) return d;
		q.pop();

		for (int a : adjs[v]) {
			if (!vis[a]) {
				vis[a] = 1;
				q.push({a, d+1});
			}
		}
	}

	return -1;
}

void getAdjs() {
	Tab tab;
	readTab(tab);
	litTab(tab);

	for (int d = 0; d < 6; d++) {
		getAdjs(tab, d);
	}
}

void solve() {
	getAdjs();
	printf("%d\n", bfs());
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
