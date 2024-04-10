class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        countMap[0] = 1;
        int preFix = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            preFix += nums[i];
            int key = preFix % k;
            if (key < 0) key += k;
            count += countMap[key];
            countMap[key] ++;
        }
        return count;
    }
};