# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def accCredit(self, node, p, q):
        if not node:
            return 0, None
        val = 0
        val += 1 if node is p or node is q else 0
        c, n = self.accCredit(node.left, p, q)
        if n:
            return 0, n
        val += c
        c, n2 += self.accCredit(node.right, p, q)
        if n2:
            return 0, n2
        val += c
        return val, None
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        _, node = self.accCredit(root, p, q)
        return node