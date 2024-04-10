import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private LinkedList<Integer> path = new LinkedList<>();
    private List<String> ans = new LinkedList<>();

    private String pathToString() {
        StringBuilder sb = new StringBuilder();

        for (Integer item : path) {
            if (sb.length() != 0) {
                sb.append("->");
            }
            sb.append(item.toString());
        }
        return sb.toString();
    }

    private void dfs(TreeNode node) {
        if (node.left == null && node.right == null) {
            ans.add(pathToString());
            return;
        }
        if (node.left != null) {
            path.add(node.left.val);
            dfs(node.left);
            path.pollLast();
        }
        if (node.right != null) {
            path.add(node.right.val);
            dfs(node.right);
            path.pollLast();
        }
    }

    public List<String> binaryTreePaths(TreeNode root) {
        path.clear();
        ans.clear();

        if (root == null) {
            return ans;
        }

        path.add(root.val);
        dfs(root);

        return ans;
    }
}