#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int vis[N];
bool cycle = false;

void dfs(int cur) {
	vis[cur] = 1;
	for (auto x : gr[cur]) {
		if (vis[x] == 0) {
			dfs(x);
		}
		else if (vis[x] == 1) {
			// backedge
			cycle = true;
		}
	}
	vis[cur] = 2;
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
	}

	// O(n)
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) dfs(i);
	}

	cout << cycle << '\n';

}