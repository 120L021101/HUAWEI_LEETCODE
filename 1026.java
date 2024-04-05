import java.util.ArrayList;
import java.util.Arrays;
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
    private List<Integer> dfs(TreeNode node) {
        if (node == null) {
            return new ArrayList<Integer>(Arrays.asList(Integer.MAX_VALUE, Integer.MIN_VALUE, 0));
        }
        List<Integer> left_res = dfs(node.left);
        List<Integer> right_res = dfs(node.right);
        Integer minVal = Math.min(Math.min(node.val, left_res.get(0)), right_res.get(0));
        Integer maxVal = Math.max(Math.max(node.val, left_res.get(1)), right_res.get(1));
        Integer retMax = Math.max(Math.abs(node.val - minVal), Math.abs(node.val - maxVal));
        retMax = Math.max(retMax, Math.max(left_res.get(2), right_res.get(2)));
        return new ArrayList<>(Arrays.asList(minVal, maxVal, retMax));
    }
    public int maxAncestorDiff(TreeNode root) {
        return dfs(root).get(2);
    }
}