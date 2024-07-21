#include<bits/stdc++.h>
using namespace std;

// https://codeforces.com/contest/25/problem/D
struct DSU {
	vector<int> par, sz;
	int connectedComponents;
	DSU(int n) {
		par.resize(n + 1);
		sz.resize(n + 1, 1);
		iota(par.begin(), par.end(), 0);
		connectedComponents = n;
	}

	// O(k)
	int getSuper(int x) {
		if (x == par[x]) return x;
		return par[x] = getSuper(par[x]);
	}

	// add bi-directional edge between X and Y
	// O(k)
	// return true if they were not connected
	// false if they were already connected
	bool unite(int x, int y) {
		x = getSuper(x);
		y = getSuper(y);
		if (x != y) {
			// x and y are part of different sets
			par[x] = y;
			sz[y] += sz[x];
			sz[x] = 0;
			connectedComponents--;
			return true;
		}
		return false;
	}

	// O(k)
	bool isConnected(int x, int y) {
		return getSuper(x) == getSuper(y);
	}

	int getComponentSize(int x) {
		return sz[getSuper(x)];
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;

	DSU H(n);
	vector<pair<int, int> > cyclic_edges;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		if (!H.unite(x, y)) {
			// its a cyclic edge
			cyclic_edges.push_back(pair<int, int>(x, y));
		}
	}

	vector<int> super_parents;
	for (int i = 1; i <= n; i++) {
		if (H.par[i] == i) {
			super_parents.push_back(i);
		}
	}

	cout << cyclic_edges.size() << '\n';

	int k = 1;
	for (auto x : cyclic_edges) {
		cout << x.first << " " << x.second
		     << " " << super_parents[0] << " " << super_parents[k] << '\n';
		k++;

	}






}