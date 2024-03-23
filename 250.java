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
    private boolean isSame = false;
    private Integer val = 0;
    private int calculate(TreeNode node) {
        if (node == null) {
            isSame = true;
            val = 5;
            return 0;
        }
        Boolean isLeftSame = false, isRightSame = false;
        Integer valLeft = 0, valRight = 0;
        int numLeft = calculate(node.left);
        isLeftSame = isSame; valLeft = val;
        int numRight = calculate(node.right);
        isRightSame = isSame; valRight = val;
        isSame = (valLeft == node.val || node.left == null) && (valRight == node.val || node.right == null) && isLeftSame && isRightSame;
        int numThis = isSame ? 1 : 0;
        val = node.val;
        return numLeft + numRight + numThis;
    }
    public int countUnivalSubtrees(TreeNode root) {
        return calculate(root);
    }
}