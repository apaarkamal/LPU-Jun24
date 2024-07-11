#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int prev_index[N];

struct Query {
	int l, r, ans;
};

struct Fenwick {
	vector<int> v;
	int n;
	Fenwick(int n) {
		v.resize(n + 5, 0);
		this->n = n + 4;
	}

	void add(int idx, int val) {
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

	memset(prev_index, -1, sizeof(prev_index));

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> query_indexed[n];

	int num_queries;
	cin >> num_queries;
	Query q[num_queries];

	for (int i = 0; i < num_queries; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].l--; q[i].r--;

		query_indexed[q[i].r].push_back(i);
	}

	Fenwick tree(n);

	for (int i = 0; i < n; i++) {
		if (prev_index[a[i]] == -1) {
			// this is the first occurence
			prev_index[a[i]] = i;
			tree.add(i, 1);
		}
		else {
			tree.add(prev_index[a[i]], -1);
			tree.add(i, 1);
			prev_index[a[i]] = i;
		}

		for (auto idx : query_indexed[i]) {
			q[idx].ans = tree.query(q[idx].l, q[idx].r);
		}
	}

	for (int i = 0; i < num_queries; i++) {
		cout << q[i].ans << '\n';
	}







}