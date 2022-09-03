#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

#define vi vector<int>
#define pb push_back
#define trace(x) cerr<<#x<<": "<<x<<endl;

using ll = long long;

using namespace std;

int main(){
	fastio;
	int n;
	cin >> n;
	n /= 2;
	vector<int> ds;
	stack<int> ss;
	for (ll i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			ds.push_back(i);
			if (i*i != n) ss.push(n / i);
		}
	}

	cout << ds.size() + ss.size() << "\n";
	for (int d : ds) cout << d << " ";
	while (!ss.empty()) {
		cout << ss.top() << " ";
		ss.pop();
	}

	cout << "\n";

	return 0;
}

