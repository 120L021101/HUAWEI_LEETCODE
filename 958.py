# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from typing import *

class Solution:
    def bfs(self, node) -> bool:
        level = [node]
        while True:
            next_level = []
            flag = False
            for node in level:
                left_node = node.left
                right_node = node.right
                flag = flag or (left_node is None or right_node is None)
                next_level.append(left_node)
                next_level.append(right_node)
            level = next_level
            if flag:
                break
        
        for i, node in enumerate(level):

            if node is None:
                for n in level[i + 1:]:
                    if n is not None:
                        return False
                return True

            elif node.left is not None or node.right is not None:
                return False
        return True

    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:
        return self.bfs(node=root)