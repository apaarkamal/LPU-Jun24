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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return head;

		// at least two node
		ListNode* ahead = head->next->next;
		ListNode* nextt = head->next;

		head->next->next = head;
		head->next = swapPairs(ahead);

		return nextt;
	}
};