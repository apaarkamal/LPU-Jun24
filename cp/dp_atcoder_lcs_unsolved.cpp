#include<bits/stdc++.h>
using namespace std;

string s, t;
const int N = 3005;

int memo[N][N];

// O(|s|*|t|)
int lcs(int i, int j) {
	if (i >= s.size() || j >= t.size()) return 0;
	if (memo[i][j] != -1) return memo[i][j];
	if (s[i] == t[j]) return memo[i][j] = 1 + lcs(i + 1, j + 1);
	else return memo[i][j] = max(lcs(i + 1, j), lcs(i, j + 1));
}

void trace(int i, int j) {
	if (i >= s.size() || j >= t.size()) return;
	if (lcs(i, j) == 1 + lcs(i + 1, j + 1)) {
		cout << s[i];
		trace(i + 1, j + 1);
	}
	else if (lcs(i, j) == lcs(i + 1, j)) {
		trace(i + 1, j);
	}
	else if (lcs(i, j) == lcs(i, j + 1)) {
		trace(i, j + 1);
	}

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> s >> t;

	memset(memo, -1, sizeof(memo));

	// cout << lcs(0, 0);
	trace(0, 0);






}