#include<bits/stdc++.h>
using namespace std;

// O(n)
int f(int i, int h[], int memo[],  int n) {
	if (i == n - 1) return 0;

	if (memo[i] != -1) return memo[i];

	// go to f(i+1) with some cost
	int ans1 = INT_MAX;
	if (i + 1 < n) {
		ans1 = f(i + 1, h, memo, n) + abs(h[i] - h[i + 1]);
	}

	int ans2 = INT_MAX;
	// go to f(i+2)
	if (i + 2 < n) {
		ans2 = f(i + 2, h, memo, n) + abs(h[i] - h[i + 2]);
	}

	// return the minimum of these two
	return memo[i] = min(ans1, ans2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int h[n], memo[n];
	for (int i = 0; i < n; i++) {
		cin >> h[i];
		memo[i] = -1;
	}

	cout << f(0, h, memo, n);
}