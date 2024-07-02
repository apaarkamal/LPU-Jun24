#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
int divi[N];
int res[N];


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) {
			divi[j]++;
		}
	}


	for (int m = 1; m < N; m++) {
		for (int n = m; n < N; n += m) {
			// m divide i
			// div[m] also divides div[n]
			if (divi[n] > 3 && divi[n] % divi[m] == 0) {
				res[n]++;
			}

		}
	}

	vector<int> ans;
	for (int i = 1; i < N; i++) {
		if (divi[i] < 3 || divi[i] != res[i]) continue;
		// cout << i << " " << res[i] << '\n';
		ans.push_back(i);
	}

	for (int i = 107; i < ans.size(); i += 108) {
		cout << ans[i] << '\n';
	}





}