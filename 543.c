/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define max(a, b) (a > b ? a : b)

int find_depth(struct TreeNode * node, int* max_lengh) {
    if (!node) {
        return 0;
    }
    int left_depth = find_depth(node->left, max_lengh);
    int right_depth = find_depth(node->right, max_lengh);
    *max_lengh = max(*max_lengh, left_depth + right_depth);
    return max(left_depth, right_depth) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int length = 0;
    find_depth(root, &length);
    return length;   
}