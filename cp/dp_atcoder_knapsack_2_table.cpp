#include<bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, W;
	cin >> n >> W;
	int w[n + 1], v[n + 1];
	int sum_val = 0;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
		sum_val += v[i];
	}
	int dp[n + 1][sum_val + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= sum_val + 1; j++) {
			dp[i][j] = 1e18;
		}
	}

	// yes i can make 0 value using empty set
	dp[0][0] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum_val; j++) {
			// dont include the current element
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);

			// if include
			if (j >= v[i]) {
				dp[i][j] = min(dp[i][j], w[i] + dp[i - 1][j - v[i]]);
			}
		}
	}



	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 0; j <= sum_val; j++) {
	// 		if (dp[i][j] > 1e15) {
	// 			cout << -1 << " ";
	// 		}
	// 		else {
	// 			cout << dp[i][j] << " ";
	// 		}
	// 	} cout << '\n';
	// }

	int ans = 0;
	for (int j = 0; j <= sum_val; j++) {
		if (dp[n][j] <= W) {
			ans = j;
		}
	}

	cout << ans;






}