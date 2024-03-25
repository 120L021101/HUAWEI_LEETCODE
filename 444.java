import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class Solution {
    public boolean sequenceReconstruction(int[] nums, List<List<Integer>> sequences) {
        Map<Integer, List<Integer>> edges = new HashMap<>();
        int[] degree = new int[nums.length + 1];
        for (List<Integer> sequence : sequences) {
            for (int i = 0; i < sequence.size() - 1; ++i) {
                int node1 = sequence.get(i), node2 = sequence.get(i + 1);
                if (!edges.containsKey(node1)) edges.put(node1, new ArrayList<Integer>());
                edges.get(node1).add(node2);
                degree[node2] ++;
            }
        }
        List<Integer> topo = new LinkedList<>();
        for (int i = 1; i < degree.length; ++i) {
            if (0 == degree[i]) {
                topo.add(i);
            }
        }
        while (topo.size() == 1) {
            List<Integer> nextLevel = new LinkedList<>();
            for (Integer linkedNode : edges.getOrDefault(topo.get(0), new ArrayList<Integer>())) {
                degree[linkedNode] --;
                if (0 == degree[linkedNode]) {
                    nextLevel.add(linkedNode);
                }
            }
            topo.remove(0);
            topo.addAll(nextLevel);
        }
        return topo.size() == 0;
    }
}