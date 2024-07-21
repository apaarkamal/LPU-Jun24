#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int vis[N];

void bfs(int src) {
	queue<int> Q;

	Q.push(src);
	vis[src] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		cout << cur << '\n';
		Q.pop();
		for (auto x : gr[cur]) {
			if (!vis[x]) {
				Q.push(x);
				vis[x] = 1;
			}
		}
	}

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
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	bfs(1);

}