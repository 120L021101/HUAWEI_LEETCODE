# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def find_leaves(self, node, fa):
        if node is None:
            return
        if (node.left is None) and (node.right is None):
            self.leaves.append(node)
        
        self.father_map[node] = fa
        self.find_leaves(node.left, node)
        self.find_leaves(node.right, node)

    def find_minStr(self):
        level = self.leaves
        while len(level) != 0:
            level.sort(key=lambda x : x.val)
            remaining_level = [level[0]]
            self.path.append(level[0].val)
            for i in range(1, len(level)):
                if not level[i].val == remaining_level[0].val:
                    break
                remaining_level.append(level[i])

            next_level = []
            for node in remaining_level:
                if self.father_map[node] is None:
                    return
                next_level.append(self.father_map[node])
            level = next_level


    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        self.father_map, self.leaves, self.path = {}, [], []
        self.find_leaves(root, None)
        self.find_minStr()
        
        Str = []

        for n in self.path:
            Str.append(chr(ord('a') + n))
        return ''.join(Str)