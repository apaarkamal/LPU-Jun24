#include<bits/stdc++.h>
using namespace std;

void fun(int open, int close, string res, int n) {
	if (open + close == n) {
		cout << res << '\n';
		return;
	}
	if (open < n / 2) {
		fun(open + 1, close, res + "(", n);
	}
	if (open > close) {
		fun(open, close + 1, res + ")", n);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	fun(0, 0, "", n);
}