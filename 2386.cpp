
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long max_sum = 0;
        for (int &num : nums) {
            if (num > 0) {
                max_sum += num;
            } else {
                num = -num;
            }
        }
        sort(nums.begin(), nums.end(), [](int &a, int &b) {return a < b;});
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});
        for (int i = 0; i < k - 1; ++i) {
            auto p = pq.top();  pq.pop();
            if (p.second == nums.size()) continue;
            pq.push({p.first + nums[p.second], p.second + 1});
            if (!p.second) continue;
            pq.push({p.first - nums[p.second - 1] + nums[p.second], p.second + 1});
        }
        return max_sum - pq.top().first;
    }
};