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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return head;;
        int length = 0;
        for (ListNode * pointer = head; pointer != nullptr; pointer = pointer->next)
            length ++;
        k %= length;
        if (k == 0) return head;
        ListNode header(-1, head);
        ListNode * fast_pointer = head, * slow_pointer = head;
        for (int i = 0; i < k; ++i) {
            fast_pointer = fast_pointer->next;
        }
        while (fast_pointer->next != nullptr) {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next;
        }
        ListNode * new_head = slow_pointer->next;
        slow_pointer->next = nullptr;
        fast_pointer->next = header.next;
        return new_head;
    }
};