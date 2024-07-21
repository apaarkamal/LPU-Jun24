#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> gr[N];
int memo[N][2];

int dp(int cur, bool take, int par = 0) {
	int ans = take;
	if (memo[cur][take] != -1) return memo[cur][take];
	for (auto x : gr[cur]) {
		if (x != par) {
			if (take) {
				ans += min(dp(x, 0, cur), dp(x, 1, cur));
			}
			else {
				ans += dp(x, 1, cur);
			}
		}
	}
	return memo[cur][take] = ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}

	memset(memo, -1, sizeof(memo));

	cout << min(dp(1, 0), dp(1, 1));






}