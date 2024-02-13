/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define max(a, b) (a > b ? a : b)
void dfs(struct TreeNode* node, int* contiuneLength, int* TotalMax) {
    if (!node) { return ; }
    int this_val = node->val;
    *contiuneLength = 1;
    if (node->left) {
        int left_length = 0;
        dfs(node->left, &left_length, TotalMax);
        if (node->left->val == this_val + 1) {
            *contiuneLength = max(*contiuneLength, left_length + 1);
        }
    }
    if (node->right) {
        int right_length = 0;
        dfs(node->right, &right_length, TotalMax);
        if (node->right->val == this_val + 1) {
            *contiuneLength = max(*contiuneLength, right_length + 1);
        }
    }
    *TotalMax = max(*TotalMax, *contiuneLength);
}

int longestConsecutive(struct TreeNode* root) {
    int contiuneLength = 0, maxLength = 0;
    dfs(root, &contiuneLength, &maxLength);
    return maxLength;
}