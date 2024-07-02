#include<bits/stdc++.h>
using namespace std;

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	} cout << '\n';
}

// <= unstable
// < stable
// worst case - O(n^2)
// best case - O(n^2)
void selectionSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		int min_idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[min_idx]) {
				min_idx = j;
			}
		}
		swap(a[min_idx], a[i]);
	}
}

// inplace sorting? - it is inplace
// worst case - O(n*n)
// best case - O(n)
// stable or not? - stable
void bubbleSort(int a[], int n) {
	int swapCount = 1;
	while (swapCount) {
		swapCount = 0;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] > a[i + 1]) {
				swap(a[i], a[i + 1]);
				swapCount++;
			}
		}
		printArray(a, n);
	}
}

// Best case - O(n)
// Worst Case - O(n*n) - (descending order)
// stable? - stable
// in-place? - not in place
void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int savedValue = a[i];
		int j = i - 1;
		// break at j where a[j]<=savedValue
		// while does not loop if already sorted
		while (j >= 0 && a[j] > savedValue) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = savedValue;
		printArray(a, n);
	}
}

// in place
void insertionSortInPlace(int arr[], int n) {
	for (int i = 1; i < n ; i++) {
		int j = i ;
		while (j > 0 && arr[j - 1] > arr[j]) {
			swap(arr[j - 1] , arr[j]);
			j-- ;
		}
	}
}

// Space Complexity - O(max(mx_elent, n))
// Time Complexity - O(mx_elent + n)
// inplace - NO
// un stable
void countSort(int a[], int n) {
	int mx = *max_element(a, a + n);
	int cnt[mx + 1];
	for (int i = 0; i <= mx; cnt[i] = 0, i++);
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
	}
	for (int i = 0, k = 0; i <= mx; i++) {
		while (cnt[i]--) {
			a[k] = i;
			k++;
		}
	}
}

// Space Complexity - O(max(mx_elent, n))
// Time Complexity - O(mx_elent + n)
// inplace - NO
// stable
void countSortStable(int a[], int n) {
	int mx = *max_element(a, a + n);
	vector<int> cnt[mx + 1];
	for (int i = 0; i < n; i++) {
		cnt[a[i]].push_back(a[i]);
	}
	for (int i = 0, k = 0; i <= mx; i++) {
		for (int x : cnt[i]) {
			a[k] = x;
			k++;
		}
	}
}

// Time Complexity - O(n)
int getMaxLevel(int a[], int n) {
	int mx = 0;
	for (int i = 0; i < n; i++) {
		string s = to_string(a[i]);
		mx = max(mx, (int)s.size());
		// cout << a[i] << " " << s << " " << s.size() << '\n';
	}
	return mx;
}

// O(n)
void countRadixSort(int a[], int n, int level) {
	vector<int> cnt[10];
	for (int i = 0; i < n; i++) {
		int digit = (a[i] / (int)pow(10, level)) % 10;
		cnt[digit].push_back(a[i]);
	}
	for (int i = 0, k = 0; i <= 9; i++) {
		for (int x : cnt[i]) {
			a[k] = x;
			k++;
		}
	}
}

// O(n + n) ~ O(n)
void radixSort(int a[], int n) {
	int maxLevel = getMaxLevel(a, n);
	for (int i = 0; i < maxLevel; i++) {
		countRadixSort(a, n, i);
	}
}

// O(n+m)
void mergeTwoSortedArrays(int a[],
                          int i, int ii, int j, int jj) {

	// i -> ii = ii - i + 1
	// j -> jj = jj - j + 1
	// jj - j + ii - i + 2
	// jj - (ii + 1) + ii - i +2
	// jj - i + 1

	// ii. and j are consecutive
	// j = ii+1

	int temp[jj - i + 1], k = 0, temp_i = i, temp_jj = jj;
	while (i <= ii || j <= jj) {
		if (i <= ii && j <= jj) {
			if (a[i] <= a[j]) {
				temp[k++] = a[i++];
			}
			else {
				temp[k++] = a[j++];
			}
		}
		else {
			if (i <= ii) {
				temp[k++] = a[i++];
			}
			else if (j <= jj) {
				temp[k++] = a[j++];
			}
		}
	}

	// copy back from temp to a
	for (int it = temp_i, k = 0; it <= temp_jj; it++) {
		a[it] = temp[k++];
	}
}

// O(nlogn)
void mergeSortHelper(int a[], int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = (left + right) / 2;
	// [left - mid]
	// [mid+1 - right]
	mergeSortHelper(a, left, mid);
	mergeSortHelper(a, mid + 1, right);

	// merge both the sorted arrays
	mergeTwoSortedArrays(a, left, mid, mid + 1, right);
}

void mergeSort(int a[], int n) {
	mergeSortHelper(a, 0, n - 1);
}

// index of the partition
int doPartition(int a[], int left, int right) {
	int pivot = a[right];
	int  i = left;
	for (int j = left; j < right; j++) {
		if (a[j] < pivot) {
			swap(a[i], a[j]);
			i++;
		}
	}

	swap(a[i], a[right]);

	return i;
}

// worst case - O(n^2)
// best case - O(n logn)
void quickSortHelper(int a[], int left, int right) {
	if (left >= right) return;

	int partition = doPartition(a, left, right);
	// sort left
	quickSortHelper(a, left, partition - 1);
	// sort right
	quickSortHelper(a, partition + 1, right);
}

void quickSort(int a[], int n) {
	quickSortHelper(a, 0, n - 1);
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

	// selectionSort(a, n);
	// bubbleSort(a, n);
	// insertionSort(a, n);
	// insertionSortInPlace(a, n);
	// countSort(a, n);
	// countSortStable(a, n);
	// radixSort(a, n);
	// mergeSort(a, n);
	// quickSort(a, n);

	printArray(a, n);



	// cout << (9876 % (int)(pow(10, 2)) % 10);

}