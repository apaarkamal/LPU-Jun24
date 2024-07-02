#include<bits/stdc++.h>
using namespace std;

void pushAtBottom(stack<int> &St, int x) {
	if (St.empty()) {
		St.push(x);
		return;
	}

	int val = St.top();
	St.pop();
	pushAtBottom(St, x);
	St.push(val);
}

void reverseStack(stack<int> &St) {
	if (St.empty()) return;

	int x = St.top();
	St.pop();
	reverseStack(St);
	pushAtBottom(St, x);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	stack<int> St;
	St.push(1);
	St.push(2);
	St.push(3);
	St.push(4);
	St.push(5);

	reverseStack(St);

	while (!St.empty()) {
		cout << St.top() << '\n';
		St.pop();
	}

}