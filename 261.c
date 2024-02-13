typedef struct _LinkedNode {
    int identity;
    struct _LinkedNode* next;
} LinkedNode;

void freeLink(LinkedNode *node) {
    if (!node) return;
    freeLink(node->next);
    free(node);
}

void addNode(LinkedNode *node, int addedNode) {
    LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
    newNode->next = node->next;
    newNode->identity = addedNode;
    node->next = newNode;
}

bool isNotLoop(int father, int visitNode, unsigned char* visited, LinkedNode** linkedEdges) {
    visited[visitNode] = true;
    for (LinkedNode *edge = linkedEdges[visitNode]->next;
            edge != NULL; edge = edge->next) {
        int nextNode = edge->identity;
        if (nextNode == father) continue;
        if (visited[nextNode]) return false;
        if (!isNotLoop(visitNode, nextNode, visited, linkedEdges)) {
            return false;
        }
    }
    return true;
}

bool validTree(int n, int** edges, int edgesSize, int* edgesColSize) {
    LinkedNode* linkedEdges[n];
    for (int i = 0; i < n; ++i) {
        linkedEdges[i] = (LinkedNode *)malloc(sizeof(LinkedNode));
        linkedEdges[i]->next = NULL;
        linkedEdges[i]->identity = -1;
    }
    for (int **start = edges, **end = edges + edgesSize; start != end; ++start) {
        int node1 = (*start)[0];
        int node2 = (*start)[1];
        addNode(linkedEdges[node1], node2);
        addNode(linkedEdges[node2], node1);
    }
    unsigned char visited[n];
    memset(visited, 0, sizeof(unsigned char) * n);
    
    bool isTree = isNotLoop(-1, 0, visited, linkedEdges);
    for (int i = 0; i < n; ++i) {
        isTree &= visited[i];
        freeLink(linkedEdges[i]);
    }
    return isTree;
}