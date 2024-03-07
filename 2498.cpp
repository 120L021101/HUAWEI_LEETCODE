class Solution {
public:
    int maxJump(vector<int>& stones) {
        int max_val = stones[1] - stones[0];
        for (int i = 2; i < stones.size(); ++i) {
            max_val = fmax(max_val, stones[i] - stones[i - 2]);
        }
        return max_val;
    }
};