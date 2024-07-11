#include<bits/stdc++.h>
using namespace std;

struct BinaryTree {
	vector<pair<int, int> > st;

	pair<int, int> getDefault() {
		return pair<int, int>(INT_MAX, -1);
	}

	int n;
	pair<int, int> defaultValue = getDefault();

	pair<int, int> compare(pair<int, int> a, pair<int, int> b) {

		if (a.first != b.first) {
			return min(a, b);
		}
		return (a.second > b.second ? a : b);
	}

	BinaryTree(int n) {
		st.resize(4 * n, defaultValue);
		this->n = n;
	}

	// O(log(n))
	// index
	int query(int start, int end, int node, int val) {
		if (start == end) {
			return st[node].second;
		}

		int mid = (start + end) / 2;
		if (st[2 * node + 2].first < val) {
			// query on right
			return query(mid + 1, end, 2 * node + 2, val);
		}
		else if (st[2 * node + 1].first < val) {
			// query on left
			return query(start, mid, 2 * node + 1, val);
		}
		else {
			return -1;
		}
	}

	// O(log(n))
	void update(int start, int end, int node, int idx, int val) {
		if (start == end) {
			st[node] = pair<int, int>(val, idx);
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

	int query(int val) {
		return query(0, n - 1, 0, val);
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
	BinaryTree tree(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		tree.update(i, a[i]);
	}

	int res[n];

	// O(nlogn)
	for (int i = 0; i < n; i++) {
		// cout << tree.query(a[i]) << " " ;
		int smallestIdx = tree.query(a[i]);
		if (smallestIdx == -1 || smallestIdx < i) {
			res[i] = -1;
		}
		else {
			res[i] = smallestIdx - i - 1;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}

}