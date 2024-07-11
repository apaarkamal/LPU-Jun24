/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* atIndex(ListNode *head, int idx) {
		if (idx == 0) return NULL;
		// idx == head
		ListNode* cur = head;
		idx--;
		while (idx--) {
			cur = cur->next;
		}
		return cur;
	}
	ListNode* reverseBetween(ListNode* head, int left, int right) {
		if (left == right) return head;

		ListNode* leftNode = atIndex(head, left);
		ListNode* rightNode = atIndex(head, right);
		ListNode* beforeLeftNode = atIndex(head, left - 1);
		ListNode* afterRightNode = atIndex(head, right + 1);

		ListNode* prev = leftNode, *cur = leftNode->next;

		while (prev != rightNode) {
			ListNode* ahead = cur->next;
			cur->next = prev;
			prev = cur;
			cur = ahead;
		}

		leftNode->next = afterRightNode;
		if (beforeLeftNode == NULL) {
			head = rightNode;
		}
		else {
			beforeLeftNode->next = rightNode;
		}
		return head;
	}
};