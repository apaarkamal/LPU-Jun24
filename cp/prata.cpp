#include<bits/stdc++.h>
using namespace std;

#define db(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << '\n'; }
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

// sqrt(time)
int paranthasByCook(int rank, int time) {
	int n = 1;
	while (n * (n + 1) * rank <= time * 2) {
		n++;
	}
	return n - 1;
}

// log(time)
// binary search for parathas
int paranthasByCookBinarySearch(int rank, int time) {
	int left = 0, right = time;
	while (left < right) {
		int mid = (left + right) / 2;
		if (rank * mid * (mid + 1) <= 2 * time) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left - 1;
}

// O(l * log(time))
int getTotalParathas(int cook[], int l, int time) {
	int paranthas = 0;
	for (int i = 0; i < l; i++) {
		paranthas += paranthasByCookBinarySearch(cook[i], time);
	}
	return paranthas;
}

void solve() {
	int p, l;
	cin >> p >> l;
	int cook[l];
	for (int i = 0; i < l; i++) {
		cin >> cook[i];
	}

	// O(l * sqrt(time) * ans)
	// for (int time = 1;; time++) {
	// 	int paranthas = getTotalParathas(cook, l, time);
	// 	if (paranthas >= p) {
	// 		cout << time << '\n';
	// 		return;
	// 	}
	// }

	// lower bound for time
	int left = 0, right = 1e7;

	// O(l * log(time) * log(1e7))
	while (left < right) {
		int mid = (left + right) / 2;
		if (getTotalParathas(cook, l, mid) >= p) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	cout << left << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// cout << paranthasByCook(8, 4000000) << '\n';
	// cout << sqrt(4000000);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}