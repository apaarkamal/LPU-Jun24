#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

vector<int> gr[N];
int sum[N], nodes[N];
int res[N];

// O(n)
void dfs(int cur, int par) {
	nodes[cur] = 1;
	for (auto child : gr[cur]) {
		if (child != par) {
			dfs(child, cur);

			nodes[cur] += nodes[child];

			sum[cur] += sum[child] + nodes[child];
		}
	}
}

// O(n)
void reroot(int cur, int par) {
	// always assume the cur is the root node
	res[cur] = sum[cur];

	for (auto child : gr[cur]) {
		if (child != par) {
			// break the edge between cur and child
			sum[cur] = sum[cur] - sum[child] - nodes[child];
			nodes[cur] = nodes[cur] - nodes[child];

			// now add edge back and make cur as child
			sum[child] = sum[child] + sum[cur] + nodes[cur];
			nodes[child] = nodes[child] + nodes[cur];

			reroot(child, cur);

			nodes[child] = nodes[child] - nodes[cur];
			sum[child] = sum[child] - sum[cur] - nodes[cur];

			nodes[cur] = nodes[cur] + nodes[child];
			sum[cur] = sum[cur] + sum[child] + nodes[child];
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(0, -1);

	reroot(0, -1);

	for (int i = 0; i < n; i++) {
		// cout << sum[i] << " ";
		cout << res[i] << " ";
	}


}