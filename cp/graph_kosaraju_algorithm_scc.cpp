#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N], grr[N];
int vis[N];
vector<int> topo, scc[N];

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) {
			dfs(x);
		}
	}
	topo.push_back(cur);
	return;
}


void dfsReverse(int cur, int comp) {
	vis[cur] = 1;
	scc[comp].push_back(cur);
	for (auto x : grr[cur]) {
		if (vis[x] == 0) {
			dfsReverse(x, comp);
		}
	}
	return;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		// directed graph
		gr[x].push_back(y);
		grr[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) dfs(i);
	}

	reverse(topo.begin(), topo.end());

	memset(vis, 0, sizeof(vis));

	int component = 1;

	for (auto x : topo) {
		if (!vis[x]) {
			dfsReverse(x, component);
			component++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (auto x : scc[i]) {
			cout << x << " ";
		}
		cout << '\n';
	}







}