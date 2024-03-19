class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size();
        int diff = (n + 1) ^ (n + 2);
        for (int i = 0; i < n; ++i) {
            diff ^= nums[i] ^ (i + 1);
        }
        int judge = diff & -diff;
        int p1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & judge) {
                p1 ^= nums[i];
            }
            if ((i + 1) & judge) {
                p1 ^= i + 1;
            }
        }
        if ((n + 1) & judge) p1 ^= n + 1;
        if ((n + 2) & judge) p1 ^= n + 2;
        return {p1, diff ^ p1};
    }
};