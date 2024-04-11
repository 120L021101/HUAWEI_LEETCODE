class Solution {

    private Map<Integer, Set<Integer>> edgeMap;
    private int[] nums;
    private int[] answer;
    private List<Integer> arr = Arrays.asList(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47);

    // key structure
    private static final Integer MAX_VAL = 50;
    private int[][] ancestor;

    private void dfs(int node, int father) {
        Set<Integer> thisCd = getCd(nums[node]);

        // find ancestor
        int find_ancestor = father;
        boolean flag = true;
        while (find_ancestor != -1 && flag) {
            flag = false;
            for (Integer cd : thisCd) {
                if (ancestor[find_ancestor][cd] != find_ancestor) {
                    find_ancestor = ancestor[find_ancestor][cd];
                    flag = true;
                    break;
                }
            }
        }
        answer[node] = find_ancestor;
        // dp
        for (int i = 2; i <= MAX_VAL; ++i) {
            if (thisCd.contains(i)) ancestor[node][i] = father == -1 ? father : ancestor[father][i];
            else ancestor[node][i] = node;
        }

        // dfs
        for (Integer linkedNode : edgeMap.get(node)) {
            if (linkedNode == father) continue;
            dfs(linkedNode, node);
        }
    }

    public int[] getCoprimes(int[] nums, int[][] edges) {

        if (nums.length == 1) return new int[]{-1};

        // initial
        this.nums = nums;
        this.answer = new int[nums.length];
        Arrays.fill(this.answer, -1);
        this.edgeMap = new HashMap<>();
        for (int[] edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            if (!edgeMap.containsKey(node1)) edgeMap.put(node1, new HashSet<>());
            if (!edgeMap.containsKey(node2)) edgeMap.put(node2, new HashSet<>());
            edgeMap.get(node1).add(node2);
            edgeMap.get(node2).add(node1);
        }
        ancestor = new int[nums.length][MAX_VAL + 1];
        for (int i = 0; i < nums.length; ++i) {
            for (int j = 0; j < ancestor[0].length; ++j) {
                ancestor[i][j] = -1;
            }
        }
        dfs(0, -1);
        // drawTree(0, -1, 0);

        return answer;
    }

    private Set<Integer> getCd(int val) {
        Set<Integer> cdSet = new HashSet<>();
        for (int i : arr) {
            if (val % i == 0) {
                cdSet.add(i);
            }
        }
        return cdSet;
    }
}