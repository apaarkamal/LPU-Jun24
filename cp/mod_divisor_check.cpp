#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	int c;
	cin >> c;

	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		res = (res * 10) % c + (s[i] - '0');
		res %= c;
	}

	cout << (res == 0 ? "divisible" : "not divisible");

}