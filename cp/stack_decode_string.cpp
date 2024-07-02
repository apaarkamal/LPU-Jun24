#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string decodeString(string s) {
		int n = s.size();
		int num = 0;
		stack<int> St;
		stack<string> string_stack;
		string temp;
		for (int i = 0; i < n; i++) {
			// cout << i << " " << num << '\n';
			if (s[i] == '[') {
				St.push(num);
				num = 0;
				string_stack.push(temp);
				temp = "";
			}
			else if (s[i] == ']') {
				int mul = St.top();
				string res;
				while (mul--) {
					res += temp;
				}
				temp = string_stack.top() + res;
				// remove
				string_stack.pop();
				St.pop();
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				temp += s[i];
			}
			else {
				num *= 10;
				num += (s[i] - '0');
			}
		}
		return temp;
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
	cout << H.decodeString(s);

}