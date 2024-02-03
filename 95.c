/**
 * Definition for a binary tree node.
 * struct struct TreeNode {
 *     int val;
 *     struct struct TreeNode *left;
 *     struct struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


struct TreeNode** dfs(int start, int end, int* size) {
    if (start > end) {
        struct TreeNode** tree_set = (struct TreeNode **)malloc(sizeof(struct TreeNode *));
        tree_set[0] = NULL;
        *size = 1;
        return tree_set;
    }

    struct TreeNode** tree_set = (struct TreeNode **)malloc(0);
    for (int this_node = start; this_node <= end; ++this_node) {
        int left_size = 0, right_size = 0;
        struct TreeNode** left_tree_set = dfs(start, this_node - 1, &left_size);
        struct TreeNode** right_tree_set = dfs(this_node + 1, end, &right_size);

        for (int left_node = 0; left_node < left_size; left_node ++) {
            for (int right_node = 0; right_node < right_size; right_node ++) {
                struct TreeNode* this_node_pointer = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                this_node_pointer->val = this_node;
                struct TreeNode* left_node_pointer = left_tree_set[left_node];
                struct TreeNode* right_node_pointer = right_tree_set[right_node];
                this_node_pointer->left = left_node_pointer;
                this_node_pointer->right = right_node_pointer;

                (*size)++;
                tree_set = (struct TreeNode **)realloc(tree_set, sizeof(struct TreeNode *) * (*size));
                tree_set[(*size) - 1] = this_node_pointer;
            }
        }
    }
    return tree_set;
}

struct TreeNode** generateTrees(int n, int* returnSize) {
    *returnSize = 0;
    return dfs(1, n, returnSize);
}