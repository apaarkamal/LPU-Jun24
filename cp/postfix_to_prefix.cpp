#include<bits/stdc++.h>
using namespace std;

bool is_operand(char ch) {
	return (ch >= 'a' && ch <= 'z')
	       || (ch >= 'A' && ch <= 'Z');
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// postfix to infix
	string postfix;
	cin >> postfix;

	stack<string> St;

	for (int i = 0; i < postfix.size(); i++) {
		if (is_operand(postfix[i])) {
			string s = string(1, postfix[i]);
			St.push(s);
		}
		else {
			// operator
			string op1 = St.top();
			St.pop();
			string op2 = St.top();
			St.pop();

			string expression = postfix[i] + op2 + op1;
			St.push(expression);
		}
	}


	cout << St.top();

}