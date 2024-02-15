/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* update(struct TreeNode* node, struct TreeNode** root) {
    if (!node->left) {
        *root = node;
        return node;
    }
    struct TreeNode* newRoot = update(node->left, root);
    newRoot->left = node->right;
    newRoot->right = node;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct TreeNode* upsideDownBinaryTree(struct TreeNode* root) {
    if (!root) return NULL;
    struct TreeNode* newRoot = NULL;
    update(root, &newRoot);
    return newRoot; 
}