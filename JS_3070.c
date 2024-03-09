int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {
    int number = 0;
    int row = gridSize, col = gridColSize[0];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i && j) {
                grid[i][j] = grid[i][j] + grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
            }
            if (i && !j) {
                grid[i][j] = grid[i - 1][j] + grid[i][j];
            }
            if (!i && j) {
                grid[i][j] = grid[i][j - 1] + grid[i][j];
            }
            if (grid[i][j] <= k)
                number ++;
        }
    }
    return number;
}