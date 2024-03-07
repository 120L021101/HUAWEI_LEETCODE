class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int & a, int & b) {
            return a > b;
        });
        unordered_map<long long, int> count_map;
        for (long long num : nums) {
            long long father = num * num;
            if (count_map.count(father)) {
                count_map[num] = count_map[father] + 1;
            }
            else {
                count_map[num] = 1;
            }
        }
        int max_val = -1;
        for (auto iterator = count_map.begin(), end = count_map.end();
                    iterator != end; iterator ++) {
            if (iterator->second > max_val) {
                max_val = iterator->second;
            }
        }
        return max_val == 1 ? -1 : max_val;
    }
};