class Solution:

    def find(self, father_map, node):
        if father_map[node] != node:
            father_map[node] = self.find(father_map, father_map[node])
        return father_map[node]

    def merge(self, father_map, node1, node2):
        root1 = self.find(father_map, node1)
        root2 = self.find(father_map, node2)
        father_map[root2] = root1
        return root1 != root2

    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        father_map = list(range(0, 1 + len(edges)))
        for edge in edges:
            node1, node2 = edge
            if not self.merge(father_map, node1, node2):
                return edge
        return None
