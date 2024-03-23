import java.util.ArrayList;
import java.util.Arrays;
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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        if (root == null) return new ArrayList<>();
        List<List<Integer>> positiveOrder = new LinkedList<>();
        List<TreeNode> levelOrder = new LinkedList<>(Arrays.asList(root));
        while (!levelOrder.isEmpty()) {
            List<Integer> copy = new ArrayList<>();
            for (TreeNode node : levelOrder) {
                copy.add(node.val);
            }
            positiveOrder.add(0, copy);
            int size = levelOrder.size();
            for (int i = 0; i < size; ++i) {
                TreeNode node = levelOrder.get(0);
                levelOrder.remove(0);
                if (node.left != null) {
                    levelOrder.add(node.left);
                }
                if (node.right != null) {
                    levelOrder.add(node.right);
                }
            }
        }

        return positiveOrder;
    }
}