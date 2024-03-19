class Solution {

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return { 0 };
        unordered_map<int, vector<int>> edge_map;
        unordered_map<int, int> degree;
        for (vector<int>& edge : edges) {
            int node1 = edge[0], node2 = edge[1];
            degree[node1] ++;
            degree[node2] ++;
            if (!edge_map.count(node1)) edge_map[node1] = {};
            if (!edge_map.count(node2)) edge_map[node2] = {};
            edge_map[node1].push_back(node2);
            edge_map[node2].push_back(node1);
        }
        deque<int> zero_node;
        for (auto itr = degree.begin(), end = degree.end(); itr != end; itr++) {
            if (itr->second == 1) {
                zero_node.push_back(itr->first);
            }
        }
        int node1 = 0, node2 = 1;
        vector<int> alive (n, 1);
        while (int size = zero_node.size()) {
            for (int i = 0; i < size; ++i) {
                int node = zero_node[0];
                alive[node] = 0;
                for (int con_node : edge_map[node]) {
                    if (!alive[con_node]) continue;
                    if (1 == --degree[con_node]) {
                        zero_node.push_back(con_node);
                    }
                }
                zero_node.pop_front();
            }
            if (zero_node.size() == 1) {
                node1 = zero_node[0]; node2 = -1;
            }
            if (zero_node.size() == 2) {
                node1 = zero_node[0]; node2 = zero_node[1];
            }
        }
        return node2 == -1 ? vector<int>{node1} : vector<int>{node1, node2};
    }
};