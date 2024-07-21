#include<bits/stdc++.h>
using namespace std;

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

	int n, m;
	cin >> n >> m;
	vector<vector<int> > edges;
	for (int i = 0; i < m; i++) {
		vector<int> v(3);
		cin >> v[2] >> v[1] >> v[0];
		edges.push_back(v);
	}

	sort(edges.begin(), edges.end());

	DSU H(n);
	int mst = 0;

	for (auto v : edges) {
		int w = v[0], x = v[1], y = v[2];
		if (H.unite(x, y)) {
			mst += w;
		}
	}

	cout << mst;









}