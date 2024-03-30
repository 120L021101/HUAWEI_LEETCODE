#include <stdio.h>

typedef long long int lli;

#define f(x, y) ((x) * m + y)

typedef struct _LinkedXY {
    int x;
    int y;
    struct _LinkedXY * next;
} LinkedXY;

typedef LinkedXY * pLinkedXY;


int bfs(char * matrix, int n, int m) {
    unsigned char visited[n][m];
    memset(visited, 0, sizeof(unsigned char) * n * m);
    pLinkedXY level = (pLinkedXY)malloc(sizeof(LinkedXY));
    level->x = 0; level->y = 0; level->next = NULL;
    int size = 1;
    int step = 0;
    visited[0][0] = 1;
    while (size) {
        pLinkedXY nextLevel = (pLinkedXY)malloc(sizeof(LinkedXY));
        nextLevel->next = NULL;
        int nextSize = 0;
        for (int i = 0; i < size; ++i) {
            int x = level->x, y = level->y;
            if (x == n - 1 && y == m - 1) return step;
            pLinkedXY freeNode = level;
            level = level->next;
            free(freeNode);
            if (x >= 1 && !visited[x - 1][y] && matrix[f(x - 1, y)] != matrix[f(x, y)]) {
                pLinkedXY addNode = (pLinkedXY)malloc(sizeof(LinkedXY));
                visited[x - 1][y] = 1;
                addNode->x = x - 1;
                addNode->y = y;
                addNode->next = nextLevel->next;
                nextLevel->next = addNode;
                nextSize ++;
            }
            if (y >= 1 && !visited[x][y - 1] && matrix[f(x, y - 1)] != matrix[f(x, y)]) {
                pLinkedXY addNode = (pLinkedXY)malloc(sizeof(LinkedXY));
                visited[x][y - 1] = 1;
                addNode->x = x;
                addNode->y = y - 1;
                addNode->next = nextLevel->next;
                nextLevel->next = addNode;
                nextSize ++;
            }
            if (x < n - 1 && !visited[x + 1][y] && matrix[f(x + 1, y)] != matrix[f(x, y)]) {
                pLinkedXY addNode = (pLinkedXY)malloc(sizeof(LinkedXY));
                visited[x + 1][y] = 1;
                addNode->x = x + 1;
                addNode->y = y;
                addNode->next = nextLevel->next;
                nextLevel->next = addNode;
                nextSize ++;
            }
            if (y < m - 1 && !visited[x][y + 1] && matrix[f(x, y + 1)] != matrix[f(x, y)]) {
                pLinkedXY addNode = (pLinkedXY)malloc(sizeof(LinkedXY));
                visited[x][y + 1] = 1;
                addNode->x = x;
                addNode->y = y + 1;
                addNode->next = nextLevel->next;
                nextLevel->next = addNode;
                nextSize ++;
            }
        }
        level = nextLevel->next;
        free(nextLevel);
        size = nextSize;
        step ++;
    }
    return -1;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    char matrix[n][m];
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = getchar();
        }
        getchar();
    }
    int step = bfs(matrix, n, m);
    printf("%d", step);
    return 0;
}