class Solution {
    public int findChampion(int n, int[][] edges) {
        int[] degree = new int[n];
        for (int[] edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            degree[node2] ++;
        }
        int winner = -1;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0 && winner == -1) {
                winner = i;
            } else if (degree[i] == 0) {
                return -1;
            }
        }
        return winner;
    }
}