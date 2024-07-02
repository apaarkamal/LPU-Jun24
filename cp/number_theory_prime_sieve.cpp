#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> sieve;

// O(nloglogn)
void seive() {
	sieve.resize(N, 1);
	sieve[0] = sieve[1] = 0;
	for (int i = 2; i * i < N; i++) {
		// composite number
		if (sieve[i] == 0) continue;
		for (int j = i * i; j < N; j += i) {
			// not prime because multiple of i
			sieve[j] = 0;
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
		// cout << i << " " << sieve[i] << '\n';
		if (sieve[i]) cout << i << '\n';
	}

}