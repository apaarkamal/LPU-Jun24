#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> prime;
vector<int> totient;

// O(nloglogn)
void seive() {
	prime.resize(N, 1);
	prime[0] = prime[1] = 0;
	totient.resize(N);
	for (int i = 0; i < N; i++) totient[i] = i;
	for (int i = 2; i < N; i++) {
		// composite number
		if (prime[i] == 0) continue;
		for (int j = i; j < N; j += i) {
			// not prime because multiple of i
			if (i != j) {
				prime[j] = 0;
			}
			// i is a prime divisor of j
			totient[j] *= (i - 1);
			totient[j] /= i;
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	seive();

	for (int i = 2; i < N; i++) {
		cout << i << " " << totient[i] << '\n';
		// if (prime[i]) cout << i << '\n';
	}

}