#include<bits/stdc++.h>
using namespace std;

int states;
vector<int> memo;

// 21891 for n = 20
// n = 39
int fib(int n) {
	states++;
	if (n <= 1) return n;

	if (memo[n] != -1) return memo[n];

	memo[n] = fib(n - 1) + fib(n - 2);

	return memo[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	memo.resize(n + 1, -1);

	cout << fib(n) << '\n' << states;

}