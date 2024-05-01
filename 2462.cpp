class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> heap(cmp);
        
        int l_idx = 0, r_idx = costs.size() - 1;
        for (int cnt = 0; cnt < candidates; ++cnt) {
            if (l_idx == r_idx) {
                heap.push({costs[l_idx], l_idx});
                l_idx += 1;
                r_idx -= 1;
            }
            if (l_idx > r_idx) {
                break;
            }
            heap.push({costs[l_idx], l_idx});
            heap.push({costs[r_idx], r_idx});
            l_idx += 1;
            r_idx -= 1;
        }
        long long totalCost = 0LL;
        
        for (int i = 0; i < k; ++i) {
            vector<int> top = heap.top();
            heap.pop();
            int cost = top[0], idx = top[1];
            totalCost += cost;
            if (l_idx > r_idx) {
                continue;
            }
            if (idx < l_idx) {
                heap.push({costs[l_idx], l_idx});
                l_idx += 1;
            }
            else {
                heap.push({costs[r_idx], r_idx});
                r_idx -= 1;
            }
        }

        return totalCost;
    }
};