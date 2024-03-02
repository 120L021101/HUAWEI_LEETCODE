class Solution {
public:
    bool validPartition(vector<int>& nums) {
        if (nums.size() == 2) {
            return nums[0] == nums[1];
        }
        vector<bool> dp_2 (nums.size(), 0);
        vector<bool> dp_3 (nums.size(), 0);
        vector<bool> dp_3c (nums.size(), 0);
        dp_2[1] = nums[0] == nums[1];
        dp_3[2] = nums[0] == nums[1] and nums[0] == nums[2];
        dp_3c[2] = nums[2] == nums[1] + 1 and nums[1] == nums[0] + 1;
        for (int i = 3, s = nums.size(); i < s; ++i) {
            if (nums[i] == nums[i - 1]) {
                dp_2[i] = dp_2[i - 2] || dp_3[i - 2] || dp_3c[i - 2];
            }
            if (nums[i] == nums[i - 1] and nums[i] == nums[i - 2]){
                dp_3[i] = dp_2[i - 3] || dp_3[i - 3] || dp_3c[i - 3];
            }
            if (nums[i] == nums[i - 1] + 1 and nums[i - 1] == nums[i - 2] + 1) {
                dp_3c[i] = dp_2[i - 3] || dp_3[i - 3] || dp_3c[i - 3];
            }
        }
        return dp_2[nums.size() - 1] || dp_3[nums.size() - 1] || dp_3c[nums.size() - 1];
    }
};