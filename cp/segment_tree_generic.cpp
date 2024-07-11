#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
	vector<int> st;

	int getDefault() {
		// return INT_MAX;
		// return INT_MIN;
		return 0;
		// return 0;
	}

	int n, defaultValue = getDefault();

	int compare(int a, int b) {
		// return min(a, b);
		// return max(a, b);
		return a + b;
		// return a ^ b;
	}

	// O(4*n)
	// O(nlog(n))
	void build(int start, int end, int node, int a[]) {
		if (start == end) {
			// leaf node
			st[node] = a[start];
			return;
		}
		int mid = (start + end) / 2;
		// left build
		build(start, mid, 2 * node + 1, a);
		// right build
		build(mid + 1, end, 2 * node + 2, a);
		// update the parent while returning
		st[node] = compare(st[2 * node + 1], st[2 * node + 2]);
		return ;
	}

	// O(nlogn)
	SegmentTree(int a[], int n) {
		st.resize(4 * n, defaultValue);
		this->n = n;
		build(0, n - 1, 0, a);
	}

	// O(log(n))
	int query(int start, int end, int node, int l, int r) {
		// no overlap case
		if (end < l || start > r) {
			return defaultValue;
		}
		// complete overlap case
		if (start >= l && end <= r) {
			return st[node];
		}
		// partial overlap case
		// we have to further into the subtrees
		int mid = (start + end) / 2;
		int left = query(start, mid, 2 * node + 1, l, r);
		int right = query(mid + 1, end, 2 * node + 2, l, r);

		return compare(left, right);
	}

	// O(log(n))
	void update(int start, int end, int node, int idx, int val) {
		if (start == end) {
			// start == end == idx
			st[node] = val;
			return;
		}

		int mid = (start + end) / 2;
		if (idx <= mid) {
			// left subtree
			update(start, mid, 2 * node + 1, idx, val);
		}
		else {
			// right subtree
			update(mid + 1, end, 2 * node + 2, idx, val);
		}
		// update the parent while returning
		st[node] = compare(st[2 * node + 1], st[2 * node + 2]);
		return;
	}

	int query(int l, int r) {
		return query(0, n - 1, 0, l, r);
	}

	void update(int idx, int val) {
		update(0, n - 1, 0, idx, val);
		return;
	}
};

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

	SegmentTree St(a, n);

	// range l...r
	cout << St.query(2, 6) << '\n';

	// idx, val
	St.update(4, 10);

	cout << St.query(2, 6) << '\n';
}