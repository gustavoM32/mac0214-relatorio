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
	int a;
	string b;
	cin >> a >> b;
	int time = a;
	int spare;
	
	if (b[0] == '2') {
		time += 45;
		spare = time - 90;
	} else {
		spare = time - 45;
	}

	time -= max(0, spare);
	cout << time;
	if (spare > 0) cout << "+" << spare;
	cout << "\n";
	

}

int main() {
    FASTIO;
    int tst; cin >> tst; while (tst--)
    solve();
    return 0;
}
