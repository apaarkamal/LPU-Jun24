#include<bits/stdc++.h>
#define int long long int
using namespace std;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vector<int> divisors;

	// O(sqrt(n))
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			divisors.push_back(i);
			if (i * i != n) {
				divisors.push_back(n / i);
			}
		}
	}

	sort(divisors.begin(), divisors.end());

	if (divisors.size() == 2) cout << "prime number\n";

	for (auto x : divisors) {
		cout << x << '\n';
	}

}