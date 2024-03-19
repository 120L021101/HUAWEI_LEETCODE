class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int left = k - 1, right = k + 1;
        int max_val = nums[k];
        int cur_min = nums[k];
        while (cur_min) {
            while (left != -1 and nums[left] >= cur_min) {
                left --;
            }
            while (right != nums.size() and nums[right] >= cur_min) {
                right ++;
            }
            max_val = fmax(max_val, (right - left - 1) * cur_min);
            cur_min --;
        }
        return max_val;
    }
};