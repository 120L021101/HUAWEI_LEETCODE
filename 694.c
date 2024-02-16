typedef struct _Hash_node {
    int * path;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node* Hash_table;

#define FXY(x, y) (x * col + y)

void dfs(int** grid, char* visited, int i, int j, int row, int col, int start_XY, int * path, int * path_size) {
    int XY = FXY(i, j);
    if (i == -1 || j == -1 || i == row || j == col || visited[XY] || !grid[i][j])
        return;
    path[(*path_size)++] = XY - start_XY;
    visited[XY] = 1;
    dfs(grid, visited, i, j + 1, row, col, start_XY, path, path_size);
    dfs(grid, visited, i + 1, j, row, col, start_XY, path, path_size);
    dfs(grid, visited, i, j - 1, row, col, start_XY, path, path_size);
    dfs(grid, visited, i - 1, j, row, col, start_XY, path, path_size);
}

int numDistinctIslands(int** grid, int gridSize, int* gridColSize) {
    if (gridSize == 0 || gridColSize[0] == 0) {
        return 0;
    }
    Hash_table hash_table = NULL;    
    int row = gridSize, col = gridColSize[0], size = row * col;
    char visited[size];
    memset(visited, 0, size * sizeof(char));
    int dedup_islands = 0;
    int * path = (int *)calloc(size, sizeof(int)), path_size = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!grid[i][j] || visited[FXY(i, j)])
                continue;
            path_size = 0;
            dfs(grid, visited, i, j, row, col, FXY(i, j), path, &path_size);
            Hash_node* hash_result;
            HASH_FIND(hh, hash_table, path, path_size * sizeof(int), hash_result);
            if (hash_result)
                continue;
            hash_result = (Hash_node *)malloc(sizeof(Hash_node));
            HASH_ADD_KEYPTR(hh, hash_table, path, path_size * sizeof(int), hash_result);
        }
    }
    return HASH_COUNT(hash_table);
}