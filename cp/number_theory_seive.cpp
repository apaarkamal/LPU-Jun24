#include<bits/stdc++.h>
using namespace std;

const int N = 1e4;
vector<int> sum_div, prime, sum_even_odd;
vector<int> all_div[N];


void seive() {
	sum_div.resize(N, 0);
	sum_even_odd.resize(N, 0);
	prime.resize(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			// i is a divisor of j
			if (i != 1 && i != j) {
				prime[j] = 0;
			}
			sum_div[j] += i;
			all_div[j].push_back(i);
			if (i % 2 == 0) sum_even_odd[j] += i;
			else sum_even_odd[j] -= i;
		}
	}

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	seive();

	for (int i = 1; i < N; i++) {
		// cout << i << " " << sum_div[i] << '\n';
		cout << i << " -> ";
		for (auto x : all_div[i]) cout << x << " ";
		cout << '\n';
	}

}