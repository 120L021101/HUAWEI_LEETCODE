public class Solution extends Relation {

    private int dfs(boolean[] visited, int[][] findKnows, int node) {
        boolean ifKnowsOther = false;
        visited[node] = true;
        for (int i = 0; i < visited.length; ++i) {
            if (i == node) continue;
            findKnows[node][i] = knows(node, i) ? 1 : -1;
            if (findKnows[node][i] == -1) continue;
            ifKnowsOther = true;
            if (visited[i]) continue;
            return dfs(visited, findKnows, i);
        }
        return ifKnowsOther ? -1 : node;
    }
    public int findCelebrity(int n) {
        int[][] findKnows = new int[n][n];
        int sbPerson = dfs(new boolean[n], findKnows, 0);
        if (sbPerson == -1) return -1;
        for (int i = 0; i < n; ++i) {
            if (i == sbPerson) continue;
            if (findKnows[i][sbPerson] != 0) {
                if (findKnows[i][sbPerson] == -1) return -1;
                continue;
            }
            if (!knows(i, sbPerson)) return -1;
        }
        return sbPerson;
    }
}