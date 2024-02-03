/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (!head) return head;
        unordered_set<int> occurred = {head->val};
        ListNode* fast = head, * slow = head;
        while (fast) {
            if (!occurred.count(fast->val)) {
                occurred.insert(fast->val);
                slow = slow->next = fast;
            }
            fast = fast->next;
        }
        slow->next = NULL;
        return head;
    }
};