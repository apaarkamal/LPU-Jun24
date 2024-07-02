#include<bits/stdc++.h>
using namespace std;

// N - Queen
int n;
vector<vector<char> > grid;

bool is_safe(int row, int col) {
	// vertically
	int i = row, j = col;
	while (i >= 0) {
		if (grid[i][j] == 'Q') return false;
		i--;
	}

	// left horizontal
	i = row, j = col;
	while (i >= 0 && j >= 0) {
		if (grid[i][j] == 'Q') return false;
		i--; j--;
	}

	// right horizontal
	i = row, j = col;
	while (i >= 0 && j < n) {
		if (grid[i][j] == 'Q') return false;
		i--; j++;
	}

	return true;
}

void printGrid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j];
		} cout << '\n';
	}
	cout << '\n';
	// exit(0);
}

void nqueen(int row) {
	if (row == n) {
		printGrid();
		return;
	}

	for (int col = 0; col < n; col++) {
		if (is_safe(row, col)) {
			grid[row][col] = 'Q';

			nqueen(row + 1);

			// backtracking
			grid[row][col] = '.';
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	grid.resize(n, vector<char>(n, '.'));

	nqueen(0);

}