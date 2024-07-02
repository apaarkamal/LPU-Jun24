#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;

	node(int data) {
		this->data = data;
		next = NULL;
	}
};

node* contructLL() {
	int n;
	cin >> n;

	node* head = NULL, *tail = NULL;

	while (n--) {
		int x;
		cin >> x;
		node *temp = new node(x);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = tail->next;
		}
	}

	return head;
}

void print(node* head) {
	node* cur = head;

	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << '\n';
}

node* insertAtHead(node* head, int value) {
	node* cur = new node(value);
	cur->next = head;
	head = cur;
	return head;
}

node* insertAtTail(node* head, int value) {
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}

	node* temp = new node(value);
	cur->next = temp;
	return head;
}

int lengthOfLL(node* head) {
	node* cur = head;
	int cnt = 0;
	while (cur != NULL) {
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

// insertAtK
// k==1, insert at head
node* insertAtK(node* head, int k, int value) {
	if (k == 1) return insertAtHead(head, value);
	else if (k > lengthOfLL(head)) return insertAtTail(head, value);

	k -= 2;
	node* cur = head;
	while (k--) {
		cur = cur->next;
	}

	// cur has now reached the (k-1)th node
	node* temp = new node(value);
	temp->next = cur->next;
	cur->next = temp;
	return head;
}

node* fetchTail(node* head) {
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	return cur;
}

node* leftShiftLL(node* head, int k) {
	int length = lengthOfLL(head);
	k %= length;
	k = (k + length) % length;
	if (k == 0) return head;

	node * cur = head;
	k--;
	while (k--) {
		cur = cur->next;
	}

	node* newHead = cur->next;
	cur->next = NULL;

	node* tail = fetchTail(newHead);
	tail->next = head;

	return newHead;

}

node* rightShiftLL(node* head, int k) {
	return leftShiftLL(head, lengthOfLL(head) - k);
}

node* deleteHead(node* head) {
	if (head == NULL) return head;
	node* newHead = head->next;
	delete head;
	return newHead;
}

node* deleteTail(node* head) {
	if (head == NULL) return head;
	else if (lengthOfLL(head) == 1) return deleteHead(head);

	// second last node
	node *cur = head;
	while (cur->next->next != NULL) {
		cur = cur->next;
	}

	node* temp = cur->next;
	cur->next = NULL;
	delete temp;

	return head;
}

node* deleteAtK(node *head, int k) {
	if (k == 1) return deleteHead(head);
	else if (k == lengthOfLL(head)) return deleteTail(head);
	if (k > lengthOfLL(head)) return head;

	node* cur = head;
	k -= 2;
	while (k--) {
		cur = cur->next;
	}

	node* toBeDeleted = cur->next;
	cur->next = cur->next->next;
	delete toBeDeleted;
	return head;
}

// O(n)
node* reverseLL(node* head) {
	node *cur = head, *prev = NULL;

	while (cur) {
		node* ahead = cur->next;
		cur->next = prev;
		prev = cur;
		cur = ahead;
	}

	return prev;
}

node* reverseUsingRecursion(node *head, node* prev = NULL) {
	if (head == NULL) {
		return prev;
	}
	node *ahead = head->next;
	head->next = prev;
	return reverseUsingRecursion(ahead , head);
}

node* midPoint(node* head) {
	if (lengthOfLL(head) <= 2) {
		return head;
	}

	node *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

node* mergeTwoSortedLL(node *head1, node* head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	// both are not null
	if (head1->data <= head2->data) {
		head1->next = mergeTwoSortedLL(head1->next, head2);
		return head1;
	}
	else {
		head2->next = mergeTwoSortedLL(head1, head2->next);
		return head2;
	}
}



// O(nlogn)
node* mergeSortLinkedList(node* head) {
	if (head == NULL || head->next == NULL) return head;

	node *mid_point = midPoint(head);

	node* firstHead = head;
	node* secondHead = mid_point->next;
	mid_point->next = NULL;

	firstHead = mergeSortLinkedList(firstHead);
	secondHead = mergeSortLinkedList(secondHead);

	// merge two sorted linked lists
	return mergeTwoSortedLL(firstHead, secondHead);
}

bool isCycle(node *head) {
	node *slow = head, *fast = head;

	while (slow && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) return true;
	}

	return false;
}

node* detectCyclicNode(node* head) {
	if (!isCycle(head)) return NULL;

	node *slow = head, *fast = head;

	while (1) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	// slow is at the meeting point
	fast = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}

	// return fast
	return slow;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// node* head = new node(1);
	// cout << head->data << '\n';

	node* head = contructLL();

	print(head);

	head = insertAtHead(head, 0);

	print(head);

	head = insertAtTail(head, 6);

	print(head);

	// cout << lengthOfLL(head) << '\n';

	head = insertAtK(head, 3, 10);

	print(head);

	head = leftShiftLL(head, 3);

	print(head);

	head = rightShiftLL(head, 2);

	print(head);

	head = deleteHead(head);

	print(head);

	head = deleteTail(head);
	head = deleteTail(head);

	print(head);

	head = deleteAtK(head, 2);

	print(head);

	// head = reverseLL(head);

	// print(head);

	head = reverseUsingRecursion(head);

	print(head);

	head = mergeSortLinkedList(head);

	print(head);

	head = insertAtTail(head, 15);

	print(head);

	node *tail = fetchTail(head);
	tail->next = head->next->next;

	// cout << isCycle(head) << '\n';

	node* detectedcyclicNode  = detectCyclicNode(head);

	cout << detectedcyclicNode->data << '\n';


}