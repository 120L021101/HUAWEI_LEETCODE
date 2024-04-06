import java.util.Arrays;

class TreeAncestor {
    static final int LOG = 16;
    int[][] ancestors;

    public TreeAncestor(int n, int[] parent) {
        ancestors = new int[n][LOG];
        for (int[] ancestor : ancestors) {
            Arrays.fill(ancestor, -1);
        }
        for (int i = 0; i < n; ++i) {
            ancestors[i][0] = parent[i]; // 2^0 = 1，第一个祖先，即父亲
        }
        for (int j = 1; j < LOG; ++j) {
            for (int i = 0; i < n; ++i) {
                if (ancestors[i][j - 1] != -1){
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
                }
            }
        }
    }

    public int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG && node != -1; ++j) {
            if (((k >> j) & 1) == 1) {
                node = ancestors[node][j];
            }
        }
        return node;
    }
}