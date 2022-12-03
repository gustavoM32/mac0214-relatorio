// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 2010;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

int pda[N][N][3];
int pdb[N][N][3][2];
string s;

int Bob(int i, int j, int cw, int l);

int Alice(int i, int j, int cw) {
	int &ans = pda[i][j][cw];
	if (ans != -1) return ans;

	int l = Bob(i+1, j, cw, 0);
	int r = Bob(i, j-1, cw, 1);

	if (l == 0 || r == 0) return ans = 0;
	if (l == 2 || r == 2) return ans = 2;
	return ans = 1;
}

int Bob(int i, int j, int cw, int l) {
	if (i > j) return cw;

	int &ans = pdb[i][j][cw][l];
	if (ans != -1) return ans;

	char lc = l == 0 ? s[i-1] : s[j+1];
	char nwl, nwr;

	if (s[i] < lc) nwl = 1;
	else if (s[i] > lc) nwl = 0;
	else nwl = cw;

	if (s[j] < lc) nwr = 1;
	else if (s[j] > lc) nwr = 0;
	else nwr = cw;

	int L = Alice(i+1, j, nwl);
	int r = Alice(i, j-1, nwr);

	if (L == 1 || r == 1) return ans = 1;
	if (L == 2 || r == 2) return ans = 2;
	return ans = 0;
}

void solve() {
	cin >> s;
	int n = s.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 3; k++) {
				pda[i][j][k] = pdb[i][j][k][0] = pdb[i][j][k][1] = -1;
			}
		}
	}

	int res = Alice(0, n-1, 2);
	if (res == 0) cout << "Alice\n";
	else if (res == 1) cout << "Bob\n";
	else cout << "Draw\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
