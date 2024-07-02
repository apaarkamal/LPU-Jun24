#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> prime, prime_vect;

// O(nloglogn)
void seive() {
	prime.resize(N, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i < N; i++) {
		// composite number
		if (prime[i] == 0) continue;
		for (int j = i * i; j < N; j += i) {
			// not prime because multiple of i
			prime[j] = 0;
		}
	}
	for (int i = 2; i < N; i++) {
		if (prime[i]) {
			prime_vect.push_back(i);
		}
	}
}

void solve() {
	int m, n;
	cin >> m >> n;

	// numbers lie in 1e9
	int mp[n - m + 1];

	for (int i = m; i <= n; i++) mp[i - m] = 1;

	for (auto p : prime_vect) {
		// need prime numbers till sqrt(n)
		if (p * p > n) break;

		int start;
		// prime >=m && prime <=n
		if (p >= m && p <= n) start = p * 2;
		// prime < m
		// take the first multiple of prime in the range [m...n]
		else start = (m / p) * p + (m % p == 0 ? 0 : p);

		// cancelled all the multiples of prime
		for (int i = start; i <= n; i += p) {
			mp[i - m] = 0;
		}
	}

	for (int i = m; i <= n; i++) {
		if (mp[i - m] == 1 && i != 1) {
			cout << i << '\n';
		}
	}
	cout << '\n';
	return;

}

// O(1e5*loglog(1e5)) + O(10 * O(1e5loglog(1e5)))
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	seive();
	while (t--) {
		solve();
	}
}