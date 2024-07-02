#include<bits/stdc++.h>
#define int long long int
using namespace std;

int isPerfectSquare(int n) {
	int x = sqrt(n);
	return x * x == n;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	for (int i = 1; i <= (n + 1) / 2; i++) {
		int sum1 = i * i;
		int sum2 = sum1 - n;
		if (isPerfectSquare(sum2) && sum2 < sum1) {
			cout << sum1 << " " << sum2 << '\n';
		}
	}
}