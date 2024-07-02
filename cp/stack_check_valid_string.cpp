#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkValidString(string s) {
		int n = s.size();
		stack<int> Sto, Sts;
		int open = 0, star = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				Sto.push(i);
			}
			else if (s[i] == '*') {
				Sts.push(i);
			}
			else {
				if (!Sto.empty()) {
					Sto.pop();
				}
				else if (!Sts.empty()) {
					Sts.pop();
				}
				else {
					return false;
				}
			}
		}

		while (!Sto.empty() && !Sts.empty()
		        && Sto.top() < Sts.top()) {
			Sto.pop();
			Sts.pop();
		}

		return Sto.empty();

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
	cout << H.checkValidString(s);

}