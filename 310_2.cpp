class Solution {

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<int> degree (n, 0);
        vector<vector<int>> edge_list (n, vector<int>{});
        for (vector<int>& edge : edges) {
            int &node1 = edge[0], &node2 = edge[1];
            degree[node1] ++;
            degree[node2] ++;
            edge_list[node1].push_back(node2);
            edge_list[node2].push_back(node1);
        }
        list<int> remove_node;
        for (int i = 0; i < n; ++i)
            if (1 == degree[i]) remove_node.push_back(i);
        int remove_count = 0, size;
        while (remove_count < n - 2) {
            remove_count += (size = remove_node.size());
            for (int i = 0; i < size; ++i) {
                int node = remove_node.front();
                remove_node.pop_front();
                degree[node] = 0;
                for (int &c_node : edge_list[node])
                    if (degree[c_node] && 1 == --degree[c_node]) {
                        remove_node.push_back(c_node);
                    }
            }
        }
        return vector<int>(remove_node.begin(), remove_node.end());
    }
};