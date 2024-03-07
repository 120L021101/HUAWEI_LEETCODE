class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        deque<int> current_level { 1 };
        unordered_map<int, vector<vector<int>>> map_edge;
        for (vector<int>& road : roads) {
            int node1 = road[0], node2 = road[1], distance = road[2];
            if (!map_edge.count(node1)) map_edge[node1] = {};
            if (!map_edge.count(node2)) map_edge[node2] = {};
            map_edge[node1].push_back({ node2, distance });
            map_edge[node2].push_back({ node1, distance });
        } 
        vector<char> visited (n + 1, 0);
        int min_val = -1;
        while (current_level.size()) {
            int visit_node = current_level[0];
            visited[visit_node] = 1;
            current_level.pop_front();
            if (!map_edge.count(visit_node)) continue;
            for (vector<int>& edge : map_edge[visit_node]) {
                int link_node = edge[0], cost = edge[1];
                if (min_val == -1 or cost < min_val) {
                    min_val = cost;
                }
                if (visited[link_node]) continue;
                current_level.push_back(link_node);
            }
        }
        return min_val;
    }
};