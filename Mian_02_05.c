/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* header = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* record = header;
    header->next = NULL;
    int C = 0;
    while (l1 || l2 || C) {
        int val1 = l1 ? l1->val : 0;
        int val2 = l2 ? l2->val : 0;
        int this_val = val1 + val2 + C;
        C = this_val / 10;
        this_val %= 10;
        header = header->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        header->val = this_val;
        header->next = NULL;
        l1 = l1 ? l1->next : l1;
        l2 = l2 ? l2->next : l2;
    }
    header = record->next;
    free(record);
    return header;
}
