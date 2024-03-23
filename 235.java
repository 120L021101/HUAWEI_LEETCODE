/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode findNode = null;
    private int accCredit(TreeNode node, int val1, int val2) {
        if (node == null) {
            return 0;
        }
        int val = 0;
        if (node.val == val1) {
            val += 1;
        }
        if (node.val == val2) {
            val += 1;
        }
        val += accCredit(node.left, val1, val2);
        val += accCredit(node.right, val1, val2);
        if (val == 2 && findNode == null) {
            this.findNode = node;
        }
        return val;
    }
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        this.findNode = null;
        accCredit(root, p.val, q.val);
        return this.findNode;
    }
}