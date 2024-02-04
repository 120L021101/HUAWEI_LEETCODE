

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

bool dfs(int i, int j, int** obstacleGrid, unsigned char* visited, int row_size, int col_size, int* returnSize, int*** returnPath) {
    if (obstacleGrid[i][j] || visited[i * col_size + j]) {
        visited[i * col_size + j] = 1;
        return false;
    }
    if (i == row_size - 1 && j == col_size - 1) {
        (*returnSize) ++;
        (*returnPath) = (int **)realloc(*returnPath, sizeof(int *) * (*returnSize));
        int ** new_item = *returnPath + *returnSize - 1;
        *new_item = (int *)malloc(sizeof(int) * 2);
        (*new_item)[0] = i;
        (*new_item)[1] = j;
        return true;
    }
    
    visited[i * col_size + j] = 1;
    if (i != row_size - 1) {
        bool triance_down = dfs(i + 1, j, obstacleGrid, visited, row_size, col_size, returnSize, returnPath);
        if (triance_down) {
            (*returnSize) ++;
            (*returnPath) = (int **)realloc(*returnPath, sizeof(int *) * (*returnSize));
            int ** new_item = *returnPath + *returnSize - 1;
            *new_item = (int *)malloc(sizeof(int) * 2);
            (*new_item)[0] = i;
            (*new_item)[1] = j;
            return true;
        }
    }
    if (j != col_size - 1) {
        bool triance_right = dfs(i, j + 1, obstacleGrid, visited, row_size, col_size, returnSize, returnPath);
        if (triance_right) {
            (*returnSize) ++;
            (*returnPath) = (int **)realloc(*returnPath, sizeof(int *) * (*returnSize));
            int ** new_item = *returnPath + *returnSize - 1;
            *new_item = (int *)malloc(sizeof(int) * 2);
            (*new_item)[0] = i;
            (*new_item)[1] = j;
            return true;
        }
    }
    return false;
}

int** pathWithObstacles(int** obstacleGrid, int obstacleGridSize, \
        int* obstacleGridColSize, int* returnSize, int** returnColumnSizes){
    (*returnSize) = 0;
    int row_size = obstacleGridSize, col_size = obstacleGridColSize[0];
    int** returnPath = (int **)malloc(0);
    unsigned char visited[row_size][col_size];
    memset(visited, 0, sizeof(unsigned char) * row_size * col_size);

    dfs(0, 0, obstacleGrid, visited, row_size, col_size, returnSize, &returnPath);
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    int* end = *returnColumnSizes + *returnSize, * pointer = *returnColumnSizes;
    while (pointer != end) {
        *pointer = 2;
        pointer ++;
    }
    int** start_p = returnPath, ** end_p = returnPath + *returnSize - 1;
    while (start_p < end_p) {
        int * temp = *start_p;
        *start_p = *end_p;
        *end_p = temp;
        start_p ++;
        end_p --;
    }
    return returnPath;
}
