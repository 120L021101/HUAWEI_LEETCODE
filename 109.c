/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* backtrace(struct ListNode* node_head, int length) {
    if (!length) {
        return NULL;
    }
    int mid_idx = length / 2;
    struct ListNode* mid_p = node_head;
    for (int i = 0; i < mid_idx; ++i) {
        mid_p = mid_p->next;
    }
    struct TreeNode* this_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    this_node->val = mid_p->val;
    this_node->left = backtrace(node_head, mid_idx);
    this_node->right = backtrace(mid_p->next, length - 1 - mid_idx);
    return this_node;
}


struct TreeNode* sortedListToBST(struct ListNode* head) {
    int length = 0;
    struct ListNode* p = head;
    while (p) {
        p = p->next;
        length ++;
    }    
    return backtrace(head, length);
}