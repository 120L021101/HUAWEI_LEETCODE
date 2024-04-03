import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {

    private boolean bfs(int[] nums) {
        if (nums.length == 1) return true;
        boolean[] visited = new boolean[nums.length];
        visited[0] = true;
        List<Integer> levelOrder = new LinkedList<>(Arrays.asList(0));
        while (!levelOrder.isEmpty()) {
            int currentSize = levelOrder.size();
            for (int i = 0; i != currentSize; ++i) {
                int visitIdx = levelOrder.remove(0);
                for (int step = 1; step <= nums[visitIdx]; ++step) {
                    int vIdx = step + visitIdx;
                    if (vIdx >= nums.length) break;
                    if (vIdx == nums.length - 1) return true;
                    if (visited[vIdx]) continue;
                    visited[vIdx] = true;
                    levelOrder.add(vIdx);
                }
            }
        }
        return false;
    }

    private boolean dfs(int[] nums, boolean[] visited, int idx) {
        if (idx == nums.length - 1) return true;
        for (int step = nums[idx]; step >= 1; --step) {
            int visitIdx = step + idx;
            if (visitIdx >= nums.length) continue;
            if (visited[visitIdx]) continue;
            visited[visitIdx] = true;
            if (dfs(nums, visited, visitIdx)) return true;
        }
        return false;
    }

    public boolean canJump(int[] nums) {
        return dfs(nums, new boolean[nums.length], 0);
    }
}