/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef struct _Level {
    struct TreeNode* this_node;
    struct _Level* next;
} Level;

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int ** level_order = (int **)malloc(sizeof(int *) * 0);
    *returnSize = 0;
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * 0);
    Level *level = (Level *)malloc(sizeof(Level));
    int level_node_num = 1;
    int next_level_num = 0;
    Level *start_node = (Level *)malloc(sizeof(Level));
    start_node->this_node = root;
    start_node->next = NULL;
    level->next = start_node;
    while (level_node_num) {
        Level * start = level->next, * before = level;
        Level * next_level = (Level *)malloc(sizeof(Level));
        Level * move_pointer = next_level;
        next_level->next = NULL;
        (*returnSize) ++;
        (*returnColumnSizes) = realloc(*returnColumnSizes, sizeof(int) * (*returnSize));
        (*returnColumnSizes)[*returnSize - 1] = level_node_num;
        level_order = realloc(level_order, sizeof(int **) * (*returnSize));
        int * output = level_order[*returnSize - 1] = (int *)malloc(sizeof(int) * level_node_num);
        int idx = 0;
        while (start) {
            struct TreeNode * node = start->this_node;
            output[idx ++] = node->val;
            if (node->left) {
                Level * n = (Level *)malloc(sizeof(Level));
                move_pointer = move_pointer->next = n;
                n->next = NULL;
                n->this_node = node->left;
                next_level_num ++;
            }
            if (node->right) {
                Level * n = (Level *)malloc(sizeof(Level));
                move_pointer = move_pointer->next = n;
                n->next = NULL;
                n->this_node = node->right;
                next_level_num ++;
            }
            before = start;
            start = start->next;
            free(before);
        }
        level_node_num = next_level_num;
        free(level);
        level = next_level;
        next_level_num = 0;
    }
    return level_order;
}