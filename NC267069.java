import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

class TreeNode {
    public int label;
    public List<TreeNode> next;
    
    public long dp_red;
    public long dp_white;
    
    public TreeNode(int label) {
        this.label = label;
        this.dp_red = this.dp_white = 1;
        this.next = new LinkedList<>();
    }
}

public class Main {
    
    private static Map<Integer, TreeNode> nodeMapper = new HashMap<>();
    private static TreeNode root;
    private static boolean[] visited;
    
    private static final long LOG = (long)(1e9 + 7);

    private static void dfs(TreeNode node) {
        if (node.next.size() == 1 && node != root) {
            return ;
        }
        for (TreeNode nextNode : node.next) {
            if (visited[nextNode.label]) {
                continue;
            }
            visited[nextNode.label] = true;
            dfs(nextNode);
            node.dp_red *= (nextNode.dp_red + nextNode.dp_white);
            node.dp_white *= nextNode.dp_red;
            
            node.dp_red %= LOG;
            node.dp_white %= LOG;
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        visited = new boolean[n + 1];
        visited[1] = true;
        for (int i = 1; i <= n; ++i) {
            TreeNode node = new TreeNode(i);
            nodeMapper.put(i, node);
            if (i == 1)
                root = node;
        }

        for (int i = 0; i < n - 1; ++i) {
            int v1 = sc.nextInt();
            int v2 = sc.nextInt();
            TreeNode node1 = nodeMapper.get(v1);
            TreeNode node2 = nodeMapper.get(v2);
            node1.next.add(node2);
            node2.next.add(node1);
        }
        dfs(root);
        System.out.println((root.dp_red + root.dp_white) % LOG);
        sc.close();
    }
}
