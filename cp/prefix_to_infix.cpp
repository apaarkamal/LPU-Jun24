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

	string prefix;

	cin >> prefix;


	stack<string> St;

	for (int i = prefix.size() - 1; i >= 0; i--) {
		if (is_operand(prefix[i])) {
			string s = string(1, prefix[i]);
			St.push(s);
		}
		else {
			// operator
			string op1 = St.top();
			St.pop();
			string op2 = St.top();
			St.pop();

			string expression = "(" + op1 + prefix[i] + op2 + ")";
			St.push(expression);
		}
	}

	cout << St.top();

	// Why am I not using precendence and associativity
	// while converting prefix to infix?


}