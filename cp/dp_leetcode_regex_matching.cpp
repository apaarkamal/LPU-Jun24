class Solution {
public:
	string s, p;
	vector<vector<int>> memo;
	bool dp(int i, int j) {
		if (j == p.size() && i == s.size()) return true;
		if (j == p.size()) return false;

		if (memo[i][j] != -1) return memo[i][j];

		bool ans = 0;
		if (j + 1 < p.size() && p[j + 1] == '*') {
			// zero match
			ans |= dp(i, j + 2);
			if (i < s.size() && (p[j] == '.' || s[i] == p[j])) {
				ans |= dp(i + 1, j);
			}
		}
		else {
			if (i < s.size() && (p[j] == '.' || s[i] == p[j])) {
				ans |= dp(i + 1, j + 1);
			}
		}
		return memo[i][j] = ans;
	}
	bool isMatch(string s, string p) {
		this->s = s;
		this->p = p;
		memo.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
		return dp(0, 0);
	}
};