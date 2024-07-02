#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

struct Mat {
	int sz;
	vector<vector<int> > data;

	Mat(int sz) {
		this->sz = sz;
		data.resize(sz, vector<int>(sz, 0));
	}

	void identity() {
		data.resize(sz, vector<int>(sz, 0));
		for (int i = 0; i < sz; i++) {
			data[i][i] = 1;
		}
	}

	// O(sz^3)
	Mat operator*(Mat &b) {
		Mat res(this->sz);

		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				// res[i][j]
				for (int k = 0; k < sz; k++) {
					res.data[i][j] += (this->data[i][k]
					                   * b.data[k][j]);
					res.data[i][j] %= M;
				}

			}
		}

		return res;
	}

	// T^k
	// O(log(k)*(sz^3))
	Mat operator^(int k) {
		Mat a = (*this);
		Mat res(this->sz);
		res.identity();
		while (k) {
			if (k & 1) res = res * a;
			a = a * a;
			k = k / 2;
		}
		return res;
	}

	void print() {
		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				cout << this->data[i][j] << " ";
			} cout << '\n';
		}
		cout << '\n';
	}

};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	Mat t(2);
	t.data[0][0] = t.data[0][1] = t.data[1][0] = 1;

	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;

		if (n <= 2) {
			cout << n << '\n';
			continue;
		}

		Mat res(2);
		res = t ^ n;

		cout << res.data[0][0] % M << '\n';
	}










}