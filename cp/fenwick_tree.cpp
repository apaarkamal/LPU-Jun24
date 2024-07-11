#include<bits/stdc++.h>
using namespace std;

struct Fenwick {
	vector<int> v;
	int n;
	Fenwick(int n) {
		v.resize(n + 5, 0);
		this->n = n;
	}

	void update(int idx, int val) {
		// 1 - based indexing
		idx++;
		while (idx <= n) {
			v[idx] += val;
			// add the last set bit
			idx += idx & (-idx);
		}
		return;
	}

	int query(int idx) {
		// 1 - based indexing
		idx++;
		int ans = 0;
		while (idx) {
			ans += v[idx];
			idx -= idx & (-idx);
		}
		return ans;
	}

	int query(int l, int r) {
		return query(r) - query(l - 1);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n = 5;

	Fenwick tree(n);


	tree.update(1, 5);
	tree.update(2, 3);
	tree.update(3, 4);

	cout << tree.query(0) << '\n';
	cout << tree.query(1) << '\n';
	cout << tree.query(2) << '\n';
	cout << tree.query(3) << '\n';
	cout << tree.query(4) << '\n';


	cout << tree.query(2, 3) << '\n';










}