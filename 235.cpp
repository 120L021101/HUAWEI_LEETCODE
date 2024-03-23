/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    int accCredit(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& father) {
        if (!root) return 0;
        int val = 0;
        val += root == p || root == q;
        val += accCredit(root->left, p, q, father);
        if (father) return 0;
        val += accCredit(root->right, p, q, father);
        if (father) return 0;
        if (val == 2) {
            father = root;
        }
        return val;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* father = nullptr;
        accCredit(root, p, q, father);
        return father;
    }
};