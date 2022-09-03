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
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		a[i] -= b[i];
		a[i] *= a[i];
	}
	for (int i = 1; i < n; i++) {
		a[i] += a[i-1];
	}

	int m;
	cin >> m;
	while (m--) {
		int i, j;
		cin >> i >> j;
		i--; j--;
		ll sum = a[j];
		if (i > 0) sum -= a[i-1];
		cout << setprecision(6) << fixed << sqrt(sum) << "\n";
	}

	return 0;
}

