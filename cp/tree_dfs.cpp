#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int vis[N], subtree_size[N], parent[N], depth[N], height[N];
vector<int> tour;
int entry[N], exitt[N];

void dfs(int cur, int par = 0) {
	subtree_size[cur] = 1;
	parent[cur] = par;

	tour.push_back(cur);
	entry[cur] = tour.size();

	for (auto x : gr[cur]) {
		if (x != par) {
			depth[x] = depth[cur] + 1;
			dfs(x, cur);
			subtree_size[cur] += subtree_size[x];
		}
	}

	tour.push_back(cur);
	exitt[cur] = tour.size();

	// cout << cur << " " << depth[cur] << '\n';
	// cout << cur << " " << entry[cur] << " " << exitt[cur] << '\n';

	return;
}

void printPathToRoot(int cur) {
	while (cur) {
		cout << cur << '\n';
		cur = parent[cur];
	}
}

// if x is an ancestor of y
bool isAncestor(int x, int y) {
	return entry[x] < entry[y] && exitt[x] > exitt[y];
}

int LCA(int x, int y) {
	if (x == y) return x;

	// x has more depth than y
	if (depth[x] < depth[y]) swap(x, y);

	while (depth[x] != depth[y]) {
		x = parent[x];
	}

	while (x != y) {
		x = parent[x];
		y = parent[y];
	}

	return x;
}

int distanceBetweenTwoNodes(int x, int y) {
	int lca = LCA(x, y);
	return depth[x] + depth[y] - 2 * depth[lca];
}

int diameter(int cur, int par = 0) {
	int diam = 0;

	vector<int> child_heights;
	for (auto x : gr[cur]) {
		if (x != par) {
			diam = max(diam, diameter(x, cur));
			height[cur] = max(height[cur], height[x] + 1);
			child_heights.push_back(height[x]);
		}
	}

	sort(child_heights.rbegin(), child_heights.rend());
	// find max two depths of the subtrees
	// max_first + max_second + 2
	int max_height_1 = (child_heights.size() >= 1 ? child_heights[0] + 1 : 0);
	int max_height_2 = (child_heights.size() >= 2 ? child_heights[1] + 1 : 0);

	return max(diam, max_height_1 + max_height_2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		// input the edges
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	dfs(1);

	// printPathToRoot(7);

	// cout << isAncestor(1, 4) << '\n';
	// cout << isAncestor(7, 7) << '\n';
	// cout << isAncestor(3, 7) << '\n';

	// cout << LCA(9, 13) << '\n';
	// cout << LCA(6, 12) << '\n';
	// cout << LCA(1, 9) << '\n';

	// cout << distanceBetweenTwoNodes(13, 9) << '\n';
	// cout << distanceBetweenTwoNodes(13, 10) << '\n';

	cout << diameter(12) << '\n';
}