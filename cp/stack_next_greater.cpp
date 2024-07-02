#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int next_greater[n];
	stack<int> St;
	for (int i = 0; i < n; i++) {
		// cur value -> a[i]
		while (!St.empty() && a[St.top()] < a[i]) {
			next_greater[St.top()] = i;
			St.pop();
		}
		St.push(i);
	}

	while (!St.empty()) {
		next_greater[St.top()] = -1;
		St.pop();
	}

	for (int i = 0; i < n; i++) {
		if (next_greater[i] == -1) cout << a[i] << " " << -1 << '\n';
		else {
			cout << a[i] << " " << a[next_greater[i]] << '\n';
		}
	}









}