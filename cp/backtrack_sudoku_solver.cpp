#include<bits/stdc++.h>
using namespace std;

const int n = 9;
int grid[n][n];

bool is_safe(int row, int col, int digit) {
	// row check
	for (int j = 0; j < n; j++) {
		if (grid[row][j] == digit) return false;
	}

	// col check
	for (int i = 0; i < n; i++) {
		if (grid[i][col] == digit) return false;
	}

	// 3x3 check
	int start_x = (row / 3) * 3, start_y = (col / 3) * 3;
	for (int i = start_x; i < start_x + 3; i++) {
		for (int j = start_y; j < start_y + 3; j++) {
			if (grid[i][j] == digit) return false;
		}
	}

	return true;
}

void printGrid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << grid[i][j] << " ";
		} cout << '\n';
	}
	cout << '\n';
	// exit(0);
}

void sudokuSolver(int row, int col) {
	// if (row == 1) {
	// 	printGrid();
	// }

	if (row == n) {
		printGrid();
		return;
	}

	if (grid[row][col] == 0) {
		for (int digit = 1; digit <= 9; digit++) {
			if (is_safe(row, col, digit)) {
				grid[row][col] = digit;

				if (col == 8) {
					sudokuSolver(row + 1, 0);
				}
				else {
					sudokuSolver(row, col + 1);
				}

				// backtrack
				grid[row][col] = 0;
			}
		}
	}
	else {
		if (col == 8) {
			sudokuSolver(row + 1, 0);
		}
		else {
			sudokuSolver(row, col + 1);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	sudokuSolver(0, 0);

}