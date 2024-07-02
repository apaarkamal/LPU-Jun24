#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int> > grid;

int dx[8] = { -2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1};

void printGrid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << "\t";
		} cout << '\n';
	}
	cout << '\n';
	exit(0);
}

void knightTour(int x, int y, int hop) {
	grid[x][y] = hop;

	if (hop == n * m) {
		printGrid();
	}

	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];

		if (xx >= 0 && xx < n
		        && yy >= 0 && yy < m
		        && grid[xx][yy] == 0) {
			knightTour(xx, yy, hop + 1);
		}
	}
	// backtrack
	grid[x][y] = 0;

	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n >> m;

	grid.resize(n, vector<int>(m, 0));

	int s_x, s_y;
	cin >> s_x >> s_y;

	knightTour(s_x, s_y, 1);

}