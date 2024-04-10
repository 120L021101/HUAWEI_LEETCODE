# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

from typing import *

class Solution:
    moveTime = 0

    def dfs(self, node):
        if node is None:
            return 0
    
        moveTimes = 0
        l_time = self.dfs(node.left)
        r_time = self.dfs(node.right)

        self.moveTime += abs(l_time) + abs(r_time)
        return l_time + r_time + node.val - 1

    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        
        self.dfs(node=root)

        return self.moveTime