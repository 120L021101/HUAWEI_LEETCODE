class NumArray {

private:
    vector<int> prefix;
    vector<int> record_nums;
public:
    NumArray(vector<int>& nums): prefix(nums.size(), 0), record_nums(nums.begin(), nums.end()) {
        int current_sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i] = current_sum + nums[i];
            current_sum += nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right] - prefix[left] + record_nums[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */