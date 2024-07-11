#include<bits/stdc++.h>
using namespace std;

struct Heap {
	vector<int> v;

	// log(n)
	void Heapify(int cur) {
		int min_idx = cur;
		int left = cur * 2 + 1;
		int right = cur * 2 + 2;
		if (left < v.size() && v[left] < v[min_idx]) {
			min_idx = left;
		}
		if (right < v.size() && v[right] < v[min_idx]) {
			min_idx = right;
		}
		if (min_idx != cur) {
			swap(v[min_idx], v[cur]);
			Heapify(min_idx);
		}
		return;
	}

	// (n/2)*log(n)
	void buildHeap() {
		int last_par_node = (v.size() - 2) / 2;
		for (int i = last_par_node; i >= 0; i--) {
			Heapify(i);
		}
	}

	// (n/2)*log(n)
	Heap(vector<int> arr) {
		v = arr;
		buildHeap();
	}

	int top() {
		return v[0];
	}

	bool isEmpty() {
		return v.empty();
	}

	int size() {
		return v.size();
	}

	// log(n)
	void pop() {
		// remove v[0]
		swap(v[0], v.back());
		// remove the last element
		v.pop_back();
		// make heap again
		Heapify(0);
	}

	// O(logn)
	void push(int val) {
		v.push_back(val);
		int cur = v.size() - 1;
		int par = (cur - 1) / 2;
		while (cur > 0  && v[par] > v[cur]) {
			swap(v[par], v[cur]);
			cur = par;
			par = (cur - 1) / 2;
		}
	}

	void printHeapSorted() {
		while (!isEmpty()) {
			cout << top() << " ";
			pop();
		}
		cout << '\n';
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	Heap H(v);

	// for (int i = 0; i < n; i++) {
	// 	cout << H.v[i] << " ";
	// }

	// cout << H.top() << '\n';

	H.pop();
	// cout << H.top() << '\n';

	H.pop();
	// cout << H.top() << '\n';

	// H.push(1);
	H.push(100);

	// cout << H.top() << '\n';

	H.printHeapSorted();




}