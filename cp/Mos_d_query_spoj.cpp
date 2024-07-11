#include<bits/stdc++.h>
using namespace std;

struct Query {
	int l, r, idx, block, ans;
};

// Mo's Comparator
bool comp(Query q1, Query q2) {
	if (q1.block == q2.block) return q1.r < q2.r;
	return q1.block < q2.block;
}

bool compIdx(Query q1, Query q2) {
	return q1.idx < q2.idx;
}

const int N = 1e6 + 1;
int cnt[N], distinct_values;

void include(int val) {
	if (cnt[val] == 0) distinct_values++;
	cnt[val]++;
}

void exclude(int val) {
	cnt[val]--;
	if (cnt[val] == 0) distinct_values--;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, len_blocks;
	cin >> n;
	len_blocks = sqrt(n);
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}


	int len_q;
	cin >> len_q;
	Query queries[len_q];
	for (int i = 0; i < len_q; i++) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].l--; queries[i].r--;
		queries[i].block = queries[i].l / len_blocks;
		queries[i].idx = i;
	}

	sort(queries, queries + len_q, comp);

	int l = 0, r = 0;

	for (int i = 0; i < len_q; i++) {
		int cur_left = queries[i].l;
		int cur_right = queries[i].r;

		// imagine that l and r are already on
		// the previous query

		// make r move to right
		while (r <= cur_right) {
			include(a[r]);
			r++;
		}

		// make r move to left
		while (r > cur_right + 1) {
			r--;
			exclude(a[r]);
		}

		// make l move to left
		while (l > cur_left) {
			l--;
			include(a[l]);
		}

		// make l move to right
		while (l < cur_left) {
			exclude(a[l]);
			l++;
		}

		queries[i].ans = distinct_values;
	}

	sort(queries, queries + len_q, compIdx);

	for (int i = 0; i < len_q; i++) {
		// cout << queries[i].l + 1 << " " << queries[i].r + 1 << queries[i].idx << " ";
		cout << queries[i].ans << '\n';
	}


}