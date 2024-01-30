class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ret_ans;
        sort(begin(nums), end(nums));
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int current_val = nums[i] + nums[start] + nums[end];
                if (current_val == 0) {
                    ret_ans.insert({nums[i], nums[start], nums[end]});
                    start ++;
                    continue;
                }
                if (current_val > 0) {
                    end --;
                } else {
                    start ++;
                }
            }
        }
        return vector<vector<int>>(ret_ans.begin(), ret_ans.end());
    }
};