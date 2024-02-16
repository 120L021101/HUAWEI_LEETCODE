class Solution {

private:
    inline int find(vector<int>& ancestor, int node) {
        return ancestor[node] == node ? node : find(ancestor, ancestor[node]);
    }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> ancestor (edges.size() + 1);
        vector<int> parent (edges.size() + 1);
        iota(ancestor.begin(), ancestor.end(), 0); // 0, 1, 2, 3, 4, 5, 6 .....
        iota(parent.begin(), parent.end(), 0);     // 0, 1, 2, 3, 4, 5, 6 .....

        decltype(edges.begin()) conflict_itr = edges.end(), loop_itr = edges.end();
        for (auto itr = edges.begin(), end = edges.end(); 
                itr != end && (conflict_itr == end || loop_itr == end); ++itr) {
            
            int lnode = (*itr)[0], rnode = (*itr)[1];
            int lnode_ancestor = find(ancestor, lnode);
            int rnode_ancestor = find(ancestor, rnode);

            if (rnode_ancestor != rnode) {
                conflict_itr = itr;
                continue;
            }
            parent[rnode] = lnode;
            if (lnode_ancestor == rnode_ancestor) {
                loop_itr = itr;
                continue;
            }
            ancestor[rnode] = lnode_ancestor;
        }
        if (conflict_itr == edges.end()) {
            return *loop_itr;
        }
        if (loop_itr == edges.end()) {
            return *conflict_itr;
        }
        int end_node = (*conflict_itr)[1];
        return {parent[end_node], end_node};
    }
};