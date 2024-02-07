/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isValid(struct TreeNode* node, int** max, int** min) {
    if (!node) {
        *max = NULL;
        *min = NULL;
        return true;
    }
    int *left_max, *left_min;
    bool left_legal = isValid(node->left, &left_max, &left_min);
    if (!left_legal) return false;
    int *right_max, *right_min;
    bool right_legal = isValid(node->right, &right_max, &right_min);
    if (!right_legal) return false;
    bool this_legal = (!left_max || *left_max < node->val) &&
                      (!right_min || *right_min > node->val);
    if (!this_legal) return false;

    if (right_max) {
        *max = right_max;
    } else {
        *max = (int *)malloc(sizeof(int));
        **max = node->val;
    }
    
    if (left_min) {
        *min = left_min;
    } else {
        *min = (int *)malloc(sizeof(int));
        **min = node->val;
    }

    if (right_min) free(right_min);
    if (left_max) free(left_max);

    return true;
}

bool isValidBST(struct TreeNode* root){
    if (!root) {
        return true;
    }
    int *min, *max;
    return isValid(root, &max, &min);
}
