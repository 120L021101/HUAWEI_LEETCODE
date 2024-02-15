class Solution {

private:
    void get_next(vector<int>& pattern, vector<int>& next) {
        next = vector<int>(pattern.size(), 0);
        int j = 0;
        for (int i = 1; i < pattern.size(); ++i) {
            while (j > 0 && pattern[i] != pattern[j])
                j = next[j - 1];
            if (pattern[i] == pattern[j])
                j ++;
            next[i] = j;    
        }
    }
    int count(vector<int>& source, vector<int>& target) {
        int c = 0;
        int j = 0;
        vector<int> next;
        get_next(target, next);
        for (int i = 0; i < source.size(); ++i) {
            while (j > 0 && source[i] != target[j])
                j = next[j - 1];
            if (source[i] == target[j])
                j ++;
            if (j == next.size()) {
                c ++;
                if (j == 1) {
                    j = 0;
                    continue;
                }
                j = next[j - 2];
                while (j && source[i] != target[j]) {
                    j = next[j - 1];
                }
                if (source[i] == target[j])
                    j ++;
            }
        }
        return c;
    }

public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> pattern_itself(nums.size() - 1, 1);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                pattern_itself[i] = 0;
            } else if (nums[i] > nums[i + 1]) {
                pattern_itself[i] = -1;
            }
        }
        return count(pattern_itself, pattern);
    }
};