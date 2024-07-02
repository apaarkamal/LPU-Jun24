#include<bits/stdc++.h>
using namespace std;

int cnt = 0;

void fun(int n, string s, int minn) {
	if (n == 0) {
		// cout << s.substr(1) << '\n';
		cnt++;
		return;
	}
	for (int i = minn; i <= n; i++) {
		fun(n - i, s + "+" + to_string(i), i);
	}
}

int numFun(int n, int minn) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	if (n < minn) {
		return 0;
	}
	int ans = 0;
	// use minimum
	ans += numFun(n - minn, minn);
	// not use minimum
	ans += numFun(n, minn + 1);
	return ans;
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	fun(n, "", 1);
	cout << cnt << '\n';
	cout << numFun(n, 1) << '\n';



}