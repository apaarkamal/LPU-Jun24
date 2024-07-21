#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 1e2 + 1, M = 1e5 + 1;
int memo[N][M];

int knapsack(int i, int W, int w[], int v[], int n) {

	if (i == n) return 0;

	if (memo[i][W] != -1) return memo[i][W];

	int ans;
	// exlcude
	ans = knapsack(i + 1, W, w, v, n);

	// include
	if (w[i] <= W) {
		ans = max(ans, v[i] + knapsack(i + 1, W - w[i], w, v, n));
	}

	// include same element
	if (w[i] <= W) {
		ans = max(ans, v[i] + knapsack(i, W - w[i], w, v, n));
	}

	return memo[i][W] = ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, W;
	cin >> n >> W;
	int w[n], v[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}

	memset(memo, -1, sizeof(memo));

	cout << knapsack(0, W, w, v, n);





}