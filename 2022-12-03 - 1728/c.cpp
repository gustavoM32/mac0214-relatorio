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

void removeRep(vector<int> &a, vector<int> &b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<int> na, nb;

	int n = a.size();
	int i = 0, j = 0;

	while (i < n && j < n) {
		if (a[i] < b[j]) {
			na.push_back(a[i++]);
		} else if (a[i] > b[j]) {
			nb.push_back(b[j++]);
		} else {
			i++;
			j++;
		}
	}

	while (i < n) {
		na.push_back(a[i++]);
	}

	while (j < n) {
		nb.push_back(b[j++]);
	}

	swap(a, na);
	swap(b, nb);
}

int cnt(int v) {
	int d = 0;
	while (v > 0) {
		d++;
		v /= 10;
	}
	return d;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	removeRep(a, b);
	n = a.size();

	int res = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] >= 10) {
			res++;
			a[i] = cnt(a[i]);
		}
		if (b[i] >= 10) {
			res++;
			b[i] = cnt(b[i]);
		}
	}

	removeRep(a, b);
	n = a.size();

	for (int i = 0; i < n; i++) {
		if (a[i] > 1) {
			res++;
		}
		if (b[i] > 1) {
			res++;
		}
	}

	cout << res << "\n";
}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
