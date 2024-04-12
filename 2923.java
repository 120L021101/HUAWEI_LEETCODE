class Solution {
    public int findChampion(int[][] grid) {
        for (int i = 0; i < grid.length; ++i) {
            int sumVal = 0;
            for (int j = 0; j < grid[0].length; ++j) {
                sumVal += grid[i][j];
            }
            if (sumVal == grid.length - 1 && grid[i][i] == 0) {
                return i;
            }
        }
        return -1;
    }
}