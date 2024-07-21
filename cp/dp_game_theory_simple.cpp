#include<bits/stdc++.h>
using namespace std;

// f(n) -> winning or loosing if current player plays
bool f(int n, vector<int> &memo) {
	if (n == 0) return false;
	if (n <= 3) return true;

	if (memo[n] != -1) return memo[n];

	memo[n] = !(f(n - 1, memo) & f(n - 2, memo) & f(n - 3, memo));

	return memo[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<int> memo(n + 1, -1);

	if (f(n, memo)) {
		cout << "Alice";
	}
	else {
		cout << "Bob";
	}

}