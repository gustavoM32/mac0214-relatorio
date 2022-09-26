#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

#define vi vector<int>
#define pb push_back
#define trace(x) cerr<<#x<<": "<<x<<endl;

using ll = long long;

using namespace std;

string solve(char a, char b, char c, int n, vector<string> ss) {
	vector<string> ta, tb;

	if (ss.size() == 1) return ss[0];

	//assert(n > 0);

	for (string &s : ss) {
		if (s[n-1] == a) {
			ta.push_back(s);
		} else {
			//assert(s[n-1] == b);
			tb.push_back(s);
		}
	}

	ss.clear();

	if (tb.empty()) {
		return solve(a, c, b, n-1, ta);
	}

	return solve(c, b, a, n-1, tb);
}

int main(){
	fastio;

	int n, m;
	cin >> n >> m;

	map<string, int> ss;
	vector<string> g;

	for (int i = 1; i <= m; i++) {
		string s;
		cin >> s;
		if (ss.find(s) == ss.end()) {
			ss[s] = i;
			g.push_back(s);
		}
	}
	
	string s = solve('A', 'B', 'C', n, g);
	//cout << s << endl;
	cout << ss[s] << "\n";

	return 0;
}

