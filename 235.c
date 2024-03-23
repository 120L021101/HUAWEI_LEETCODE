/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int accCredit(struct TreeNode * node, struct TreeNode ** answerNode, struct TreeNode * p, struct TreeNode * q) {
    if (!node) return 0;
    int val = 0;
    val += node == p;
    val += node == q;
    val += accCredit(node->left, answerNode, p, q);
    if (*answerNode) return 0;
    val += accCredit(node->right, answerNode, p, q);
    if (!*answerNode && val == 2) {
        *answerNode = node;
    }
    return val;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode * answerNode = NULL;
    accCredit(root, &answerNode, p, q);
    return answerNode;
}