#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x << endl;

typedef long long ll;

const ll N = 1e6;
const ll INF = 1LL << 61;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i];
	map<string, int> correct, total;
	map<string, string> trans;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string d, e, c;
		cin >> d >> e >> c;
		total[d]++;
		trans[d] = e;

		if (c == "correct") {
			correct[d]++;
		}
	}

	ll resCorrect = 1;
	ll resTotal = 1;

	for (string w : s) {
		resTotal *= total[w];
		if (correct.find(w) != correct.end()) resCorrect *= correct[w];
		else resCorrect = 0;
	}

	if (resTotal == 1) {
		for (string w : s) {
			cout << trans[w] << " ";
		}
		if (resCorrect == 1) cout << "correct\n";
		else cout << "incorrect\n";
	} else {
		cout << resCorrect << " correct\n";
		cout << resTotal - resCorrect << " incorrect\n";

	}

}

signed main() {
	fastio;
	solve();
	return 0;
}

