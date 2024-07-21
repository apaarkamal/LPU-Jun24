#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int vis[N], dp[N];
vector<int> topo;

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

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) dfs(i);
	}

	reverse(topo.begin(), topo.end());

	// for (auto x : topo) {
	// 	cout << x << " ";
	// }

	for (int i = n - 1; i >= 0; i--) {
		int cur = topo[i];
		for (auto child : gr[cur]) {
			dp[cur] = max(dp[child] + 1, dp[cur]);
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);







}