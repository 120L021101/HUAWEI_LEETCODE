class Solution {
private:
    int dfs(int vis, int node, unordered_map<int, unordered_set<int>>& edges_map, unordered_set<int>& restr) {
        if (restr.count(node)) {
            return vis;
        }
        if (!edges_map.count(node)) {
            return vis + 1;
        }
        vis += 1;
        restr.insert(node);
        for (int linked_node : edges_map[node]) {
            vis = dfs(vis, linked_node, edges_map, restr);
        }
        return vis;
    }
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int, unordered_set<int>> edges_map;
        unordered_set<int> restr (restricted.begin(), restricted.end());
        for (auto itr = edges.begin(), end = edges.end(); itr != end; itr++) {
            int node1 = (*itr)[0];
            int node2 = (*itr)[1];
            if (!edges_map.count(node1)) {
                edges_map[node1] = {};
            }
            if (!edges_map.count(node2)) {
                edges_map[node2] = {};
            }
            edges_map[node1].insert(node2);
            edges_map[node2].insert(node1);
        }
        return dfs(0, 0, edges_map, restr);
    }
};