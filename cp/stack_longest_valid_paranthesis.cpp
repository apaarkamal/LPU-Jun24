#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size();
		stack<int> St;
		int score = 0, ans = 0;
		for (int i = 0; i < n; i++) {

			if (s[i] == '(') {
				St.push(score);
				score = 0;
			}
			else {
				if (St.empty()) {
					score = 0;
				}
				else {
					// Add '(' and ')' bracket
					score = score + 2;
					// Add ealier lenth of
					// valid paranthese before
					// corresponding opening bracket
					score += St.top();
					St.pop();
				}
			}
			ans = max(ans, score);
		}

		return ans;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	Solution H;
	cout << H.longestValidParentheses(s);

}