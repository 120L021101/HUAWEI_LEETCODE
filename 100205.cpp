
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
        unordered_map<int, int> count;
        vector<int> dedup_nums;
        for (int i = 0; i < nums.size(); ++i) {
            if (!count.count(nums[i])) {
                count[nums[i]] = 0;
            }
            if (count[nums[i]] > 2) continue;
            count[nums[i]] ++;
            dedup_nums.push_back(nums[i]);
        }
        sort(dedup_nums.begin(), dedup_nums.end(), [] (int a, int b) {return a > b;});
        int numsSize = dedup_nums.size();
        int dp[ numsSize ][ 2 ];
        memset(dp, 0, sizeof(int) * numsSize * 2);
        dp[0][0] = 1; dp[0][1] = 1;
        
        int max_length = 1;
        for (int i = 1; i < numsSize; ++i) {
            dp[i][0] = 1; dp[i][1] = 1;
            if (dedup_nums[i] == dedup_nums[i - 1] - 1) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
            }
            if (dedup_nums[i] == dedup_nums[i - 1] - 2) {
                dp[i][1] = dp[i - 1][0] + 1;
            }
            if (dedup_nums[i] == dedup_nums[i - 1]) {
                dp[i][0] = fmax(dp[i - 1][1] + 1, dp[i - 1][0]);
                dp[i][1] = dp[i - 1][1];
            }
            int this_node = fmax(dp[i][0], dp[i][1]);
            max_length = fmax(max_length, this_node);
        }
        return max_length;
    }
};