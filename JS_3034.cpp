class Solution {
private:
    bool equals(vector<int>& got, int start, vector<int>& pattern) {
        auto start_itr = got.begin() + start;
        auto end_itr = start_itr + pattern.size();
        auto that_itr = pattern.begin();
        while (start_itr != end_itr) {
            if (*start_itr != *that_itr) {
                return false;
            }
            start_itr ++;
            that_itr ++;
        }
        return true;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> pattern_itself(nums.size(), 1);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] - nums[i + 1] == 0) {
                pattern_itself[i] = 0;
            } else if (nums[i] - nums[i + 1] > 0) {
                pattern_itself[i] = -1;
            }
        }
        int s = 0;
        for (int i = 0; i < pattern_itself.size() - pattern.size(); ++i) {
            if (equals(pattern_itself, i, pattern))
                s++;
        }
        return s;
    }
};