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

int get(string &s) {
	for (char &c : s) if (c == ':') c = ' ';
	stringstream ss(s);
	int time = 0;
	int num;
	ss >> num;
	time += num;
	time *= 60;
	ss >> num;
	time += num;
	time *= 1000;
	ss >> num;
	time += num;
	return time;
}

void solve() {
	int n, v;
	cin >> n >> v;
	vector<int> nums;
	vector<vector<int>> laps(n);
	vector<pair<int, int>> ranking;
	int minlap = 1000000000;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		nums.push_back(num);
		int lapEnd = 0;
		for (int j = 0; j < v; j++) {
			string s;
			cin >> s;
			int lap = get(s);
			lapEnd += lap;
			laps[i].push_back(lap);
			minlap = min(minlap, lap);
		}
		ranking.push_back({lapEnd, i});
	}

	sort(ranking.begin(), ranking.end());
	int best = -1;
	int bestt = -1;

	for (int i = 0; i < 10; i++) {
		int lapEnd = 0;
		int p = ranking[i].second;
		for (int j = 0; j < v; j++) {
			int lap = laps[p][j];
			lapEnd += lap;
			if (lap == minlap) {
				if (best == -1 || lapEnd < bestt) {
					best = p;
					bestt = lapEnd;
				}
			}
		}
	}

	if (best == -1) cout << "NENHUM\n";
	else cout << nums[best] << "\n";

}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}