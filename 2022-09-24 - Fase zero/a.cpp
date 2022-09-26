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

void solve() {
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string p, s;
		getline(cin, p);
		getline(cin, s);
		int np = (int(s.size()) + 1) / 4;
		vector<double> grades;
		double g;
		stringstream ss(s);
		ss >> g;
		grades.push_back(g);
		if (np == 1) {
			grades.push_back(0);
		} else {
			ss >> g;
			grades.push_back(g);
			if (np >= 3) {
				ss >> g;
				grades.push_back(g);
				if (np == 4) {
					ss >> g;
					sort(grades.begin(), grades.end());
					if (g > grades[0]) grades[0] = g;
				}
			}
		}

		double sum = 0;
		for (double g : grades) sum += g;
		sum /= grades.size();
		cout << p << ": " << setprecision(1) << fixed <<  sum << "\n";
	}

}

int main() {
    FASTIO;
    //int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
