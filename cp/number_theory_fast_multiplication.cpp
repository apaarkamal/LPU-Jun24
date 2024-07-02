#include<bits/stdc++.h>
#define int long long int
using namespace std;

// fast multiplication
// binary multiplication

int fastMultiplication(int a, int b, int c) {
	int res = 0;
	while (b) {
		if (b & 1) res = (res + a) % c;
		a = (a + a) % c;
		b /= 2;
	}
	return res;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a, b, c;
	cin >> a >> b >> c;

	// cout << (a * b) % c;

	cout << fastMultiplication(a, b, c);

}