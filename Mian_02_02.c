/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
    struct ListNode* slow = head, * fast = head;
    while (k--)
        fast = fast->next;
    while (fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->val;
}
