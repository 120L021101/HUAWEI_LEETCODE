/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _Trie_node {
    struct _Trie_node * next[26];
    char * endWord;
} Trie_node;

void dfs(char** board, unsigned char * visited, int n, int m, int x, int y, Trie_node * node, int * returnSize, char ** returnStr) {
    if (x == -1 || y == -1 || x == n || y == m) return;
    int arridx = m * x + y;
    if (visited[arridx]) return;
    int idx = board[x][y] - 'a';
    node = node->next[idx];
    if (!node) return;
    if (node->endWord) {
        returnStr[(*returnSize) ++] = node->endWord;
        node->endWord = NULL;
    }
    visited[arridx] = 1;
    dfs(board, visited, n, m, x - 1, y, node, returnSize, returnStr);
    dfs(board, visited, n, m, x + 1, y, node, returnSize, returnStr);
    dfs(board, visited, n, m, x, y - 1, node, returnSize, returnStr);
    dfs(board, visited, n, m, x, y + 1, node, returnSize, returnStr);
    visited[arridx] = 0;
}

char** findWords(char** board, int boardSize, int* boardColSize, char** words, int wordsSize, int* returnSize) {
    int n = boardSize, m = boardColSize[0];
    unsigned char* visited = (unsigned char *)malloc(n * m * sizeof(unsigned char));
    Trie_node * root = (Trie_node *)calloc(1, sizeof(Trie_node));
    for (int i = 0; i < wordsSize; ++i) {
        Trie_node * node = root;
        char * pointer = words[i];
        while (*pointer != '\0') {
            int idx = *pointer - 'a';
            if (node->next[idx] == NULL) {
                node->next[idx] = (Trie_node *)calloc(1, sizeof(Trie_node));
            }
            node = node->next[idx];
            pointer ++;
        }
        node->endWord = words[i];
    }
    *returnSize = 0;
    char ** returnStr = (char **)calloc(wordsSize, sizeof(char *));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            memset(visited, 0, n * m * sizeof(unsigned char));
            dfs(board, visited, n, m, i, j, root, returnSize, returnStr);
        }
    }
    return returnStr;
}