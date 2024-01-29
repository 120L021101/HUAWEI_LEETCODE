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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int C = 0;
        ListNode header = ListNode();
        ListNode* pointer = &header;
        
        ListNode* longer = l1, * shorter = l2;
        while (longer || C) {
            int this_val = C;
            if (longer) {  
                this_val += longer->val;
                longer = longer->next;
            }
            if (shorter) {
                this_val += shorter->val;
                shorter = shorter->next;
            }
            C = this_val / 10;
            this_val %= 10;
            pointer = (pointer->next = new ListNode(this_val));
            if (!longer) {
                longer = shorter; shorter = NULL;
            }
        }
        return header.next;
    }
};