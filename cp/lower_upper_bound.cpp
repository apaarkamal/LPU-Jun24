#include<bits/stdc++.h>
using namespace std;


int lowerBound(int a[], int n, int value) {
	sort(a, a + n);

	int left = 0, right = n;


	while (left < right) {
		int mid = (left + right) / 2;
		if (value <= a[mid]) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	// left = right = lb
	return left;
}

int upperBound(int a[], int n, int value) {
	sort(a, a + n);

	int left = 0, right = n;


	while (left < right) {
		int mid = (left + right) / 2;
		if (a[mid] <= value) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	// left == right == ub
	return left;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << lowerBound(a, n, 200) << '\n';
	cout << upperBound(a, n, 200) << '\n';

	// cout << binary_search(a, a + n, 2) << '\n';
	// cout << binary_search(a, a + n, 5) << '\n';


	// int lb_index = lower_bound(a, a + n, 2) - a;
	// int ub_index = upper_bound(a, a + n, 2) - a;

	// cout << lb_index << " " << ub_index << '\n';



}