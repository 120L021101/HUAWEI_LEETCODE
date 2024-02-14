/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode * header = (struct ListNode *)malloc(sizeof(struct ListNode));
    header->next = head;
    struct ListNode * before = header, * slow = head, * fast = slow;
    while (n--) fast = fast->next;
    while (fast) {
        before = slow;
        slow = slow->next;
        fast = fast->next;
    }
    before->next = slow->next;
    // free(slow);
    struct ListNode * retAddr = header->next;
    // free(header);
    return retAddr;
}