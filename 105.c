/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

static struct TreeNode * build(int * preBegin, int * preEnd, int * inBegin, int * inEnd) {
    struct TreeNode * node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (preBegin == preEnd) {
        node->val = *preBegin;
        node->left = node->right = NULL;
        return node;
    }
    int * left_child_pre_end = preBegin;
    int * find_in_inorder = inBegin;
    while (*find_in_inorder != *preBegin) {
        find_in_inorder ++;
        left_child_pre_end ++;
    }
    struct TreeNode * left_child = build(preBegin + 1, left_child_pre_end, inBegin, find_in_inorder - 1);
    struct TreeNode * right_child = build(left_child_pre_end + 1, preEnd, find_in_inorder + 1, inEnd);
    node->left = left_child;
    node->right = right_child;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, preorder + preorderSize, inorder, inorder + inorderSize);
}