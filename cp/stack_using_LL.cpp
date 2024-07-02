#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Stack {
	struct node {
		T val;
		node* nxt;
		node(T _val) {
			this->val = _val;
			nxt = NULL;
		}
	};
	node *head = NULL;
	int sze = 0;
	// methods
	void push(int x) {
		node* newnode = new node(x);
		newnode->nxt = head;
		head = newnode;
		sze++;
	}

	bool empty() {
		return head == NULL;
	}

	T top() {
		if (empty()) {
			cout << "empty stack!\n";
			return NULL;
		}
		return head->val;
	}

	void pop() {
		if (empty()) {
			cout << "empty stack!";
			return;
		}
		node* nodeToBeDeleted = head;
		head = head->nxt;
		delete nodeToBeDeleted;
		sze--;
	}

	int size() {
		return this->sze;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	Stack<int> St;
	St.push(1);
	St.push(2);

	cout << St.top() << '\n';

	St.pop();

	cout << St.size() << '\n';

	cout << St.top() << '\n';

	St.pop();

	cout << St.top() << '\n';

	St.pop();








}