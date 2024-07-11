#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* next;
	node(int _data) {
		this->data = _data;
		this->next = NULL;
	}
};

node* construct_cll() {
	int n;
	cin >> n;
	node *head = NULL, *tail = NULL;

	while (n--) {
		int x;
		cin >> x;
		node *temp = new node(x);
		if (head == NULL) {
			// first node
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	tail->next = head;

	return head;
}

void printcll(node* head) {
	node* cur = head;
	do {
		cout << cur->data << " ";
		cur = cur->next;
	}
	while (cur != head);
	cout << '\n';
}

node* giveTail(node* head) {
	node* cur = head;
	while (cur->next != head) {
		cur = cur->next;
	}
	return cur;
}

node* insertAthead(node* head, int x) {
	if (head == NULL) return NULL;

	node* newnode = new node(x);
	newnode->next = head;
	node* tail = giveTail(head);
	tail->next = newnode;

	return newnode;
}

node* insertAtTail(node* head, int x) {
	if (head == NULL) return NULL;

	node* newnode = new node(x);
	node* tail = giveTail(head);
	tail->next = newnode;
	newnode->next = head;

	return head;
}

// todo
// same as linked list
// node* insertAtK()

node* deleteAtHead(node* head) {
	node* newHead = head->next;
	node* tail = giveTail(head);
	tail->next = newHead;

	delete head;

	return newHead;
}

node* deleteAtTail(node* head) {
	node* cur = head;
	node* tail = giveTail(head);

	while (cur->next->next != head) {
		cur = cur->next;
	}
	cur->next = head;

	delete tail;
	return head;
}

// todo
// same as linked list
// node* deleteAtK


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	node* head = construct_cll();
	printcll(head);

	// node* tail = giveTail(head);

	head = insertAthead(head, 0);
	head = insertAtTail(head, 6);

	head = deleteAtHead(head);
	head = deleteAtHead(head);
	head = deleteAtTail(head);
	head = deleteAtTail(head);
	printcll(head);

	return 0;
}