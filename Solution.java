import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class Solution {
    public int minimumSemesters(int n, int[][] relations) {
        int[] degree = new int[n + 1];
        Map<Integer, List<Integer>> edgeMap = new HashMap<>();
        for (int i = 0; i < relations.length; ++i) {
            int prevCourse = relations[i][0], nextCourse = relations[i][1];
            if (!edgeMap.containsKey(prevCourse))
                edgeMap.put(prevCourse, new LinkedList<>());
            edgeMap.get(prevCourse).add(nextCourse);
            degree[nextCourse] ++;
        }
        int terms = 0;
        List<Integer> levelOrder = new LinkedList<>();
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 0) {
                levelOrder.add(i);
            }
        }
        while (!levelOrder.isEmpty()) {
            terms += 1;
            List<Integer> nextLevel = new LinkedList<>();
            for (Integer node : levelOrder) {
                if (!edgeMap.containsKey(node))
                    continue;
                for (Integer linkedNode : edgeMap.get(node)) {
                    if (--degree[linkedNode] == 0) {
                        nextLevel.add(linkedNode);
                    }
                }
            }
            levelOrder = nextLevel;
        }
        for (int i = 1; i <= n; ++i) {
            if (degree[i] != 0)
                return -1;
        }
        return terms;
    }
}