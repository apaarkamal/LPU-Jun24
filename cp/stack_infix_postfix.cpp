#include<bits/stdc++.h>
using namespace std;

bool is_operand(char ch) {
	return (ch >= 'a' && ch <= 'z')
	       || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
	if (ch == '^') {
		// right associative
		return 3;
	}
	else if (ch == '*' || ch == '/' || ch == '%') {
		// left associative
		return 2;
	}
	else {
		// +, -
		// left associative
		return 1;
	}
}

void solve() {
	string infix;
	cin >> infix;

	stack<char> St;

	string postfix;

	for (int i = 0; i < infix.length(); i++) {
		if (is_operand(infix[i])) {
			// operand
			postfix += infix[i];
		}
		else if (infix[i] == '(' || infix[i] == ')') {
			// brackets
			if (infix[i] == '(') {
				St.push(infix[i]);
			}
			else {
				while (St.top() != '(') {
					postfix += St.top();
					St.pop();
				}
				St.pop();
			}
		}
		else {
			// operator
			// remove operators from stack if they are
			// higher precedence
			while (!St.empty()
			        && St.top() != '('
			        && precedence(St.top()) > precedence(infix[i])) {
				postfix += St.top();
				St.pop();
			}

			// remove operators same precendence but left associative
			while (!St.empty()
			        && St.top() != '('
			        && precedence(St.top()) == precedence(infix[i])
			        // left associative
			        && precedence(St.top()) <= 2) {
				postfix += St.top();
				St.pop();
			}

			// infix[i] -> operator, push it onto the stack
			St.push(infix[i]);
		}
	}

	while (!St.empty()) {
		postfix += St.top();
		St.pop();
	}

	cout << postfix << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}