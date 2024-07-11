#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Compare {
public:
	bool operator()(ListNode* x, ListNode* y) {
		return x->val > y->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, Compare> Q;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i] != NULL) {
				Q.push(lists[i]);
			}
		}

		if (Q.empty()) return NULL;

		ListNode* head = Q.top();
		Q.pop();
		if (head->next != NULL) {
			Q.push(head->next);
		}

		ListNode* tail = head;

		while (!Q.empty()) {
			ListNode* smallest = Q.top();
			Q.pop();
			if (smallest->next != NULL) {
				Q.push(smallest->next);
			}

			tail->next = smallest;
			tail = smallest;
		}

		return head;
	}
};

int main() {

}