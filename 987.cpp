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
    void dfs(map<int, vector<vector<int>>>& ans, TreeNode * node, int row, int col) {
        if (node == nullptr) { return ; }
        if (!ans.count(col)) {
            ans[col] = vector<vector<int>>();
        }
        ans[col].push_back({ row, node->val });
        if (node->left != nullptr)
            dfs(ans, node->left, row + 1, col - 1);
        if (node->right != nullptr)
            dfs(ans, node->right, row + 1, col + 1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<vector<int>>> ans;
        dfs(ans, root, 0, 0);
        vector<vector<int>> ret_ans;
        map<int, vector<vector<int>>>::iterator itr = ans.begin();
        for (; itr != ans.end(); ++itr) {
            int col = itr->first;
            vector<vector<int>> ls = itr->second;
            sort(ls.begin(), ls.end(), [](vector<int>& is, vector<int>& at) {
                return is[0] < at[0] || (is[0] == at[0] && is[1] < at[1]);
            });
            vector<int> pure_val (ls.size());
            transform(ls.begin(), ls.end(), pure_val.begin(), [](vector<int>& val) {return val[1];});
            ret_ans.push_back(move(pure_val));
        }
        return ret_ans;
    }
};