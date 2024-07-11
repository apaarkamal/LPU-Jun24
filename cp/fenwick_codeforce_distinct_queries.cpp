#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/problemset/problem/1234/D

struct Fenwick {
	vector<int> v;
	int n;
	Fenwick(int n) {
		v.resize(n + 5, 0);
		this->n = n;
	}
	void build(int n) {
		this->n = n + 5;
		v.resize(n, 0);
	}
	Fenwick() {
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


	string s;
	cin >> s;
	int n = s.size();

	Fenwick tree[26];
	for (int i = 0; i < 26; i++) {
		tree[i].build(n);
	}

	for (int i = 0; i < n; i++) {
		tree[s[i] - 'a'].update(i, 1);
	}


	int q;
	cin >> q;
	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int pos;
			char c;
			cin >> pos >> c;
			pos--;

			tree[s[pos] - 'a'].update(pos, -1);
			s[pos] = c;
			tree[s[pos] - 'a'].update(pos, 1);

		}
		else {
			int l, r;
			cin >> l >> r;
			l--; r--;
			int distinct = 0;
			for (int i = 0; i < 26; i++) {
				distinct += (tree[i].query(l, r) != 0);
			}
			cout << distinct << '\n';

		}

	}












}