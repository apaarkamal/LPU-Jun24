#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	int grid[n][m], dis[n][m];
	memset(dis, -1, sizeof(dis));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	queue<pair<int, int> > Q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				Q.push(pair<int, int>(i, j));
				dis[i][j] = 0;
			}
		}
	}

	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {1, -1, 0, 0};

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		int x = cur.first, y = cur.second;

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < n && xx >= 0 && yy < m && yy >= 0
			        && grid[xx][yy] != -1 && dis[xx][yy] == -1) {
				Q.push(pair<int, int>(xx, yy));
				dis[xx][yy] = dis[x][y] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dis[i][j] << " ";
		} cout << '\n';
	}


}