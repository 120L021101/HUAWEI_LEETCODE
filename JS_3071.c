int minimumOperationsToWriteY(int** grid, int gridSize, int* gridColSize) {
    int mid_point = gridSize / 2;
    int Y[3]; Y[0] = Y[1] = Y[2] = 0;
    for (int i = 0; i < mid_point; ++i)
        Y[grid[i][i]] ++;
    for (int i = 0; i < mid_point; ++i)
        Y[grid[i][gridSize - 1 - i]] ++;
    for (int i = mid_point; i < gridSize; ++i)
        Y[grid[i][mid_point]] ++;
    
    int NY[3]; NY[0] = NY[1] = NY[2] = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j){
            if (i == j && i < mid_point) continue;
            if (i + j == gridSize - 1 && i < mid_point) continue;
            if (i >= mid_point && j == mid_point) continue;
            NY[grid[i][j]] ++;
        }
    }
    int cost[3]; cost[0] = cost[1] = cost[2] = 0;
    cost[0] = Y[1] + Y[2] + NY[0] + fmin(NY[1], NY[2]);
    cost[1] = Y[0] + Y[2] + NY[1] + fmin(NY[0], NY[2]);
    cost[2] = Y[0] + Y[1] + NY[2] + fmin(NY[0], NY[1]);
    return fmin(cost[0], fmin(cost[1], cost[2]));
}