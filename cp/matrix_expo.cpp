#include<bits/stdc++.h>
using namespace std;

struct Matrix {
	vector<vector<int> > v;
	int n, m;
	Matrix(int n, int m) {
		this->n = n; this->m = m;
		v.resize(n, vector<int>(m , 0));
	}
	Matrix(int n, int m, vector<vector<int> > v) {
		this->n = n; this->m = m;
		this->v = v;
	}
	void printMatrix() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << v[i][j] << " ";
			} cout << '\n';
		}
		cout << '\n';
	}

	Matrix operator+ (Matrix mat) {
		Matrix res(n, m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res.v[i][j] = this->v[i][j] + mat.v[i][j];
			}
		}
		return res;
	}

	Matrix operator+= (Matrix mat) {
		return mat;
	}

};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Matrix m1(3, 3);

	vector<vector<int> > v2;

	int n, m;
	cin >> n >> m;
	v2.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v2[i][j];
		}
	}

	Matrix m2(3, 3, v2);

	m1.printMatrix();
	m2.printMatrix();

	m1 = m1 + m2;

	m1 += m2;

	m1.printMatrix();

}