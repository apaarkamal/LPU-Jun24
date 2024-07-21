#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e3 + 1, M = 1e5 + 1;
int memo[N][M];

// give me the minimum weight to make val using i element
int dp(int i, int val, int v[], int w[]) {
	if (i == 0) {
		if (val == 0) return 0;
		else return 1e18;
	}

	if (memo[i][val] != -1) return memo[i][val];

	// dont include
	int ans = dp(i - 1, val, v, w);
	// if included
	if (val >= v[i]) {
		ans = min(ans, w[i] + dp(i - 1, val - v[i], v, w));
	}

	return memo[i][val] = ans;
}


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

	memset(memo, -1, sizeof(memo));

	for (int val = sum_val; val >= 0; val--) {
		if (dp(n, val, v, w) <= W) {
			cout << val;
			break;
		}
	}



}