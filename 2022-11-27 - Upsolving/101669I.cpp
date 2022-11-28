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

int piece[10][4][3][3] = {
	{{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}}},
	{{{1, 1, 1}, {1, 0, 0}, {1, 0, 0}}},
	{{{1, 1, 0}, {0, 1, 1}, {0, 0, 1}}},
	{{{0, 1, 1}, {0, 1, 0}, {1, 1, 0}}},
	{{{1, 1, 0}, {0, 1, 0}, {0, 1, 1}}},
	{{{0, 1, 0}, {0, 1, 0}, {1, 1, 1}}},
	{{{0, 1, 0}, {1, 1, 1}, {0, 1, 1}}},
	{{{0, 1, 0}, {0, 1, 1}, {1, 1, 0}}},
	{{{0, 1, 1}, {1, 1, 1}, {1, 1, 0}}},
	{{{0, 0, 1}, {1, 1, 1}, {1, 2, 0}}}
};

int pts[10][4];

int rot[10] = {1, 4, 4, 2, 2, 4, 4, 4, 2, 4};

int tab[10][3];

void rotate(int a[3][3], int b[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = a[2-j][i];
		}
	}
}

void print(int a[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (a[i][j]) cout << "o";
			else cout << " ";
		}
		cout << "\n";
	}
	cout << endl;
}

void print_tab() {
	for (int i = 0; i < 10; i++) {
		cout << i << "|";
		for (int j = 0; j < 3; j++) {
			if (tab[i][j]) cout << "o";
			else cout << " ";
		}
		cout << "|\n";
	}
	cout << endl;
}

bool can(int p[3][3], int h) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (p[i][j] && tab[h+i][j]) return false;
		}
	}

	return true;
}

void put(int p[3][3], int h) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (p[i][j]) tab[h+i][j] = 1;
		}
	}
}

bool filled(int h) {
	return tab[h][0] && tab[h][1] && tab[h][2];
}

void clear(int h) {
	tab[h][0] = tab[h][1] = tab[h][2] = 0;
}

void swapr(int h1, int h2) {
	swap(tab[h1][0], tab[h2][0]);
	swap(tab[h1][1], tab[h2][1]);
	swap(tab[h1][2], tab[h2][2]);
}

int get_h_fit(int p[3][3]) {
	int h;

	for (h = 0; h+2 < 10; h++) {
		if (!can(p, h)) break;
	}

	return h-1;
}

bool add(int p[3][3]) {
	int h = get_h_fit(p);
	if (h == -1) return false;

	put(p, h);

	int a = h;
	int b = h+1;
	int c = h+2;

	if (filled(c)) {
		clear(c);
		swapr(c, b);
		swapr(b, a);
		a++;
		b++;
	}

	if (filled(b)) {
		clear(b);
		swapr(b, a);
		a++;
	}

	if (filled(a)) clear(a);
	
	return true;
}

bool add_piece(int piece_num, int rot) {
	if (get_h_fit(piece[piece_num][0]) == -1) return false;
	return add(piece[piece_num][rot]);
}

void copy(int orig[10][3], int dest[10][3]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			dest[i][j] = orig[i][j];

		}
	}
}

int n;
vector<int> v;
set<ll> vis;
using pii = pair<ll, ll>;

ll toCode(int tab[10][3], int op) {
	ll cd = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 3; j++) {
			cd <<= 1;
			cd += tab[i][j];
		}
	}

	return 100*cd + op;
}

int cnt = 0;

int dfs(int op, vector<pii> &mvs) {
	int bk[10][3];

	cnt++;
	if (cnt % 1000000 == 0) cout << cnt << " : " << mvs.size() << endl;
	//print_tab();

	int pc = v[op];

	copy(tab, bk);

	ll cd = toCode(tab, op);
	if (vis.find(cd) != vis.end()) return -1;
	vis.insert(cd);

	int res = 0;

	vector<pair<int, int>> rots;
	for (int j = 0; j < rot[pc]; j++) {
		rots.push_back({pts[pc][j], j});
	}

	sort(rots.begin(), rots.end());

	int win_rot = 0;

	for (auto r : rots) {
		int j = r.second;
		copy(bk, tab);
		if (add_piece(pc, j)) {

			mvs.push_back({pc, j});

			int adj_res = dfs((op+1)%n, mvs);
			if (adj_res == -1) return -1;
			if (1 + adj_res > res) {
				win_rot = j;
			}
			res = max(res, 1 + adj_res);
			mvs.pop_back();
		}
	}

	pts[pc][win_rot]++;

	vis.erase(cd);

	return res;
}

map<ll, int> mvs;

void solve() {
	for (int i = 0; i < 10; i++) {
		for (int j = 1; j < rot[i]; j++) {
			rotate(piece[i][j-1], piece[i][j]);
		}
	}

	cin >> n;

	v.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<pii> mvs;

	cout << dfs(0, mvs) << "\n";

}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
