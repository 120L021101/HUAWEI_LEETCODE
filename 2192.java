import java.util.Arrays;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

class Solution {
    public List<List<Integer>> getAncestors(int n, int[][] edges) {
        List<Set<Integer>> ancestors = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            ancestors.add(new TreeSet<>());
        }

        Map<Integer, List<Integer>> edgeMap = new HashMap<>();
        int[] degree = new int[n];
        for (int[] edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (!edgeMap.containsKey(node1)) {
                edgeMap.put(node1, new LinkedList<>());
            }
            edgeMap.get(node1).add(node2);
            degree[node2] ++;
        }

        List<Integer> bfsLevel = new LinkedList<>();
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) {
                bfsLevel.add(i);
            }
        }

        while (!bfsLevel.isEmpty()) {
            List<Integer> nextLevel = new LinkedList<>();
            for (Integer node : bfsLevel) {
                if (!edgeMap.containsKey(node)) {
                    continue;
                }
                for (Integer linkedNode : edgeMap.get(node)) {
                    ancestors.get(linkedNode).add(node);
                    ancestors.get(linkedNode).addAll(ancestors.get(node));
                    if (--degree[linkedNode] == 0)
                        nextLevel.add(linkedNode);
                }
            }
            bfsLevel.clear();
            bfsLevel.addAll(nextLevel);
        }

        List<List<Integer>> retLs = new LinkedList<>();
        for (Set<Integer> set : ancestors) {
            retLs.add(Arrays.asList(set.toArray(new Integer[set.size()])));
        }
        return retLs;
    }
}