import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    private boolean isFresh(int[][] grid, int x, int y) {
        if (x == -1 || y == -1 || grid.length == x || grid[0].length == y) {
            return false;
        }
        return grid[x][y] == 1;
    }
    public int orangesRotting(int[][] grid) {
        List<List<Integer>> level_order = new ArrayList<>();
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 2) {
                    level_order.add(Arrays.asList(i, j));
                }
            }
        }
        if (level_order.isEmpty()) {
            for (int i = 0; i < grid.length; ++i) {
                for (int j = 0; j < grid[0].length; ++j) {
                    if (grid[i][j] == 1) {
                        return -1;
                    }
                }
            }
            return 0;
        }

        int step = -1;

        while (!level_order.isEmpty()) {
            step += 1;
            int size = level_order.size();
            List<List<Integer>> next_level = new ArrayList<>();
            for (int i = 0; i < size; ++i) {
                List<Integer> pos = level_order.get(i);
                int x = pos.get(0), y = pos.get(1);
                List<List<Integer>> tryPos = Arrays.asList(
                    Arrays.asList(x - 1, y),
                    Arrays.asList(x + 1, y),
                    Arrays.asList(x, y - 1),
                    Arrays.asList(x, y + 1)
                );
                for (List<Integer> tryp : tryPos) {
                    if (!isFresh(grid, tryp.get(0), tryp.get(1))) {
                        continue;
                    }
                    grid[tryp.get(0)][tryp.get(1)] = 2;
                    next_level.add(tryp);
                }
            }
            level_order.clear();
            level_order.addAll(next_level);
        }

        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return step;
    }
}