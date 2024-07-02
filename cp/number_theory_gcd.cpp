#include<bits/stdc++.h>
using namespace std;


int gcd(int x, int y) {
	cout << x << " " << y << '\n';
	if (x == 0 || y == 0) return x + y;
	return gcd(y, x % y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;

	cout << gcd(n, m);
}