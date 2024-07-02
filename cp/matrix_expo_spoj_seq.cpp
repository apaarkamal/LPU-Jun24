#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int M = 1e9;

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

int solve() {
	int k;
	cin >> k;
	int b[k], c[k];
	for (int i = 0; i < k; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < k; i++) {
		cin >> c[i];
	}

	int n;
	cin >> n;

	if (n <= k) return b[n - 1] % M;

	Mat T(k);
	for (int i = 0; i < k; i++) {
		T.data[0][i] = c[i];
	}
	for (int i = 1; i < k; i++) {
		T.data[i][i - 1] = 1;
	}

	T = T ^ (n - k);

	int res = 0;
	for (int i = 0; i < k; i++) {
		res += (T.data[0][i] * b[k - i - 1]) % M;
		res %= M;
	}


	return res;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		cout << solve() << '\n';
	}




}