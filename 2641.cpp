/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    inline void swap(vector<TreeNode *> *& val1, vector<TreeNode *> *&val2) {
        vector<TreeNode *> *temp = val2;
        val2 = val1;
        val1 = temp;
    }
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) 
            return nullptr;
        vector<TreeNode *> ls1 { root }, ls2;
        vector<TreeNode *> *this_level(&ls1), *next_level(&ls2);
        while (!this_level->empty()) {
            long long sum_val = 0;
            for (TreeNode *& node : *this_level) {
                if (node->left) {
                    next_level->push_back(node->left);
                    sum_val += node->left->val;
                }
                if (node->right) {
                    next_level->push_back(node->right);
                    sum_val += node->right->val;
                }
            }
            for (TreeNode *& node: *this_level) {
                int family_val = 0;
                if (node->left) family_val += node->left->val;
                if (node->right) family_val += node->right->val;
                if (node->left) {
                    node->left->val = sum_val - family_val;
                }
                if (node->right) {
                    node->right->val = sum_val - family_val;
                }
            }
            this_level->clear();
            swap(this_level, next_level);
        }
        root->val = 0;
        return root;
    }
};