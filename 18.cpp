void out(vector<int> v) {
    copy (v.begin(), v.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;
}
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int> sort_nums (nums.begin(), nums.end());
        sort(sort_nums.begin(), sort_nums.end());
        // out(sort_nums);
        set<vector<int>> ret_ans;
        for (int i = 0; i < (int)sort_nums.size() - 3; ++i) {
            for (int j = i + 1; j < (int)sort_nums.size() - 2; ++j) {
                int m = j + 1, n = (int)sort_nums.size() - 1;
                while (m < n) {
                    long long current_sum = (long long)sort_nums[i] + sort_nums[j] + sort_nums[m] + sort_nums[n] - target;
                    // out({i, j, m, n, current_sum});
                    if (current_sum == 0) {
                        ret_ans.insert({sort_nums[i], sort_nums[j], sort_nums[m], sort_nums[n]});
                        m ++;
                    }
                    else if (current_sum > 0) {
                        n --;
                    }
                    else {
                        m ++;
                    }
                }
            }
        }
        return vector<vector<int>>(ret_ans.begin(),ret_ans.end());
    }
};