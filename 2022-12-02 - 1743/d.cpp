// GMC
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pb push_back
#define mp make_pair
#define sz(x) int(x.size())
#define trace(x) cerr << #x << ": " << x <<endl;

typedef long long ll;
const ll N = 50;
const ll INF = 1ll << 61;
const ll MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int i = 0;
	while (i < n && s[i] == '0') i++;

	s = s.substr(i);
	n = s.size();

	if (n == 0) {
		cout << "0\n";
		return;
	}

	vector<int> zeroes;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') zeroes.push_back(i);
	}

	if (zeroes.empty()) {
		cout << s << "\n";
		return;
	}

	string mx;

	for (int i = 0; i <= zeroes[0]; i++) {
		string cd;
		for (int j = 0; j < zeroes.size(); j++) {
			int k = zeroes[j];
			cd += s[k-i];
		}
		mx = max(mx, cd);
	}

	for (int i = 0; i < zeroes.size(); i++) {
		s[zeroes[i]] = mx[i];
	}

	cout << s << "\n";
}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
