/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct _nodeList {
    int val;
    struct _nodeList * next;
} nodeList;
typedef nodeList * pNodeList;

static int nodeCount = 0;

void append(pNodeList edgeList, int val) {
    pNodeList newNode = (pNodeList)malloc(sizeof(nodeList));
    newNode->val = val;
    newNode->next = edgeList->next;
    edgeList->next = newNode;
}

void dfs(struct TreeNode* node, pNodeList map[0]) {
    if (!node) return ;
    nodeCount ++;
    if (node->left) {
        append(map[node->val], node->left->val);
        append(map[node->left->val], node->val);
        dfs(node->left, map);
    }
    if (node->right) {
        append(map[node->val], node->right->val);
        append(map[node->right->val], node->val);
        dfs(node->right, map);
    }
}

int bfs(int start, pNodeList map[0]) {
    unsigned char visited[nodeCount + 10];
    memset(visited, 0, sizeof(visited));
    pNodeList queue = (pNodeList)malloc(sizeof(nodeList));
    queue->val = start; queue->next = NULL;
    visited[queue->val] = 1;
    int depth = 0;
    while (queue) {
        pNodeList nextQueue = (pNodeList)malloc(sizeof(nodeList));
        nextQueue->next = NULL;
        while (queue) {
            pNodeList linkedNode = map[queue->val]->next;
            while (linkedNode) {
                if (!visited[linkedNode->val]) {
                    visited[linkedNode->val] = 1;
                    append(nextQueue, linkedNode->val);
                }
                linkedNode = linkedNode->next;
            }
            queue = queue->next;
        }
        queue = nextQueue->next;
        depth ++;
    }
    return depth - 1;
}

int amountOfTime(struct TreeNode* root, int start) {
    pNodeList map[(int)1e5 + 2];
    for (int i = 0; i < sizeof(map) / sizeof(pNodeList); ++i) {
        map[i] = (pNodeList)calloc(1, sizeof(nodeList));
    }
    dfs(root, map);
    return bfs(start, map);
}