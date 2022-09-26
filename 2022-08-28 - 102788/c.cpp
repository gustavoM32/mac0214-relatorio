#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

#define vi vector<int>
#define pb push_back
#define trace(x) cerr<<#x<<": "<<x<<endl;

using ll = long long;
using namespace std;

int printed = 0;
queue<vector<int>> res;
int ts;
int t;

void vp(vector<int> &v) {
	for (int i : v) cout << i << " ";
	cout << "\n";
}

vector<int> p;

void solve(int k, int s, int e, bool rev) {
	//cout << k << " " << s << " " << e << " " << rev << " <<<< " << endl;
	if (e - s + 1 < k) return;
	if (printed == t) return;

	if (k == 0) {
		res.push(p);
		//vp(p);
		printed++;
		return;
	}

	bool crev = false;
	if (rev) crev = (e-s) % 2;

	for (int i = 0; i <= e-s; i++) {
		int j = rev ? e-i : s+i;
		p[ts-k] = j;
		//p.push_back(j);
		solve(k-1, j+1, e, rev ^ crev);
		if (printed == t) return;
		//if (res.size() == t) return;
		//p.pop_back();
		crev = !crev;
	}
}

bool check(vector<int> &a, vector<int> &b) {
	int i = 0, j = 0;
	int n = a.size();

	bool ela = false, elb = false;
	while (i < n && j < n) {
		if (a[i] == b[j]) {
			i++;
			j++;
		} else {
			if (a[i] < b[j]) {
				if (ela) return false;
				ela = true;
				i++;
			} else if (a[i] > b[j]) {
				if (elb) return false;
				elb = true;
				j++;
			} else return false;
		}
	}

	return true;
}

int main(){
	fastio;

	int n, k;
	cin >> n >> k >> t;
	p.resize(k);
	ts = k;

	solve(k, 1, n, false);

	if (res.size() < t) {
		cout << "0\n";
	} else {
		cout << t << "\n";

		//vector<int> last;
		while (!res.empty()) {
			for (int i : res.front()) {
				cout << i << " ";
			}
			cout << "\n";

			/*if (!last.empty()) {
				if (!check(last, res.front())) {
					cout << "ERROR on two above\n";
					exit(0);
				}
			}
			last = res.front();*/
			
			res.pop();
		}
	}

	return 0;
}

