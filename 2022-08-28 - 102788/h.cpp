#include <bits/stdc++.h>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define pb push_back
#define trace(x) cerr<<#x<<": "<<x<<endl;

using namespace std;
using ll = long long;

ll n, k;

const int N = 10010;

ll dp[N];

ll solve(int x){
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i-1];
		if (i - x >= 1) dp[i] += dp[i-x];
		if (dp[i] > k) return k+1;
		if (i % 7 == 0) dp[i] += dp[i/7];
		if (dp[i] > k) return k+1;
	}

	return dp[n];
}

int bb() {
	int l = 2, r = n-1;
	while (l <= r) {
		int m = (l + r) / 2;
		ll s = solve(m);

		if (s == k) {
			if (l == r) return l;
			r = m;
		} else if (s < k) r = m-1;
		else l = m+1;
	}
	
	return 0;
}

signed main(){
	fastio;

	cin>>n>>k;

	cout << bb() << endl;

	return 0;
}

