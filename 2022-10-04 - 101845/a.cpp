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

void matProd(vector<vector<ll>> &a, vector<vector<ll>> &b, vector<vector<ll>> &c) {
	int n = a.size();
	int m = a[0].size();
	int p = b[0].size();
	vector<vector<ll>> res(n, vector<ll>(p, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < m; k++) {
				res[i][j] = (res[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
			}
		}
	}
	c = res;
}

void matExp(vector<vector<ll>> &base, ll n, vector<vector<ll>> &res) {
	int d = base.size();

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			res[i][j] = ll(i == j);
		}
	}

	while (n > 0) {
		if (n % 2 == 1) matProd(res, base, res);
		matProd(base, base, base);
		n /= 2;
	}
}

void solve() {
	int s = 45;
	vector<vector<ll>> mat(s, vector<ll>(s, 0));
	for (int i = 0; i < s-1; i++) {
		mat[i][i+1] = 1;
	}
	mat[39][0] = 1;
	mat[29][0] = 4;
	mat[19][0] = 9;
	mat[9][0] = 16;

	ll n;
	cin >> n;

	vector<vector<ll>> res(s, vector<ll>(s));
	matExp(mat, n, res);


	vector<vector<ll>> rr(1, vector<ll>(s));
	rr[0][0] = 1;

	matProd(rr, res, rr);

	ll sum = 0;
	for (int i = 0; i < s; i++) {
		sum = (sum + rr[0][i]) % MOD;
		//cout << rr[0][i] << " ";
	}

	//cout << "\n";

	cout << sum << "\n";


}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
