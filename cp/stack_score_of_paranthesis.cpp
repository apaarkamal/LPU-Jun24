#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
	int scoreOfParentheses(string s) {
		int n = s.size();
		stack<int> St;
		int score = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				St.push(score);
				score = 0;
			}
			else {
				if (score == 0) {
					score = 1;
				}
				else {
					score *= 2;
				}
				score += St.top();
				St.pop();
			}
		}
		return score;
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
	cout << H.scoreOfParentheses(s);

}