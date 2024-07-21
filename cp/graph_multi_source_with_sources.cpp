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
	pair<int, int> source[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	queue<pair<int, int> > Q, S;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				Q.push(pair<int, int>(i, j));
				S.push(pair<int, int>(i, j));
				dis[i][j] = 0;
				source[i][j] = pair<int, int>(i, j);
			}
			else if (grid[i][j]) {
				source[i][j] = pair<int, int>(-1, -1);
			}
		}
	}

	int dx[4] = {0, 0, -1, 1};
	int dy[4] = {1, -1, 0, 0};

	while (!Q.empty()) {
		pair<int, int> cur = Q.front();
		Q.pop();
		pair<int, int> src = S.front();
		S.pop();
		int x = cur.first, y = cur.second;

		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < n && xx >= 0 && yy < m && yy >= 0
			        && grid[xx][yy] != -1 && dis[xx][yy] == -1) {
				Q.push(pair<int, int>(xx, yy));
				S.push(src);
				dis[xx][yy] = dis[x][y] + 1;
				source[xx][yy] = src;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dis[i][j] << " ";
		} cout << '\n';
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "{" << source[i][j].first << "," << source[i][j].second << "} ";
		} cout << '\n';
	}

}