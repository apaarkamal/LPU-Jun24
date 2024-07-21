#include<bits/stdc++.h>
#define int long long int
using namespace std;

string s;
int mod;
int memo[10005][2][101], m = 1e9 + 7;

// 10^4, {0, 1}, {100}
int fun(int index, int last, int digit_sum) {
	if (index == s.size()) {
		// if (digit_sum == 0) {
		// 	cout << res << '\n';
		// }
		return digit_sum == 0;
	}

	if (memo[index][last][digit_sum] != -1) return memo[index][last][digit_sum];

	int last_digit = 9;
	if (last) last_digit = s[index] - '0';

	int ans = 0;

	for (int digit = 0; digit <= last_digit; digit++) {
		ans += fun(index + 1, last && (digit == last_digit),
		           (digit_sum + digit) % mod);
		ans %= m;
	}

	return memo[index][last][digit_sum] = ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s;
	cin >> mod;

	memset(memo, -1, sizeof(memo));

	// 109
	// -1 because 0 is also computed
	cout << (fun(0, 1, 0) - 1 + m) % m;

}