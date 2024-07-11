#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node *next, *prev;
	node(int _data) {
		this->data = _data;
		this->next = NULL;
		this->prev = NULL;
	}
};

pair<node*, node*> construct_dll() {
	int n;
	cin >> n;
	node *head = NULL, *tail = NULL;

	while (n--) {
		int x;
		cin >> x;
		node *newnode = new node(x);
		if (head == NULL) {
			// first node
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
	}

	return {head, tail};
}

void printforward(node* head) {
	node* cur = head;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << '\n';
	return;
}

void printbackward(node* tail) {
	node* cur = tail;
	while (cur) {
		cout << cur->data << " ";
		cur = cur->prev;
	}
	cout << '\n';
	return;
}

node* insertAtHead(node *head, int x) {
	node *newnode = new node(x);
	if (head != NULL) {
		newnode->next = head;
	}
	head->prev = newnode;

	return newnode;
}

// two ways
// either pass tail or pass head
// node* insertAtTail(node *head, int x)

// node* deleteAtHead

// node* deleteAtTail

// node* deleteAtK

node* reversetough(node* head) {
	node* curnode = head, *prevnode = NULL;
	while (curnode) {
		node* aheadnode = curnode->next;
		curnode->next = prevnode;
		curnode->prev = aheadnode;
		prevnode = curnode;
		curnode = aheadnode;
	}
	return prevnode;
}

node* reverseeasy(node* head) {
	node* cur = head;
	node* oldtail = head;
	while (cur) {
		oldtail = cur;
		swap(cur->next, cur->prev);
		cur = cur->prev;
	}
	return oldtail;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	auto x = construct_dll();
	node *head = x.first, *tail = x.second;

	printforward(head);
	// printbackward(tail);

	// head = insertAtHead(head, 0);

	// head = reverseeasy(head);

	head = reversetough(head);

	printforward(head);
	// printbackward(tail);

	return 0;
}