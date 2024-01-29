class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index_map;
        for (int i = 0; i < nums.size(); ++i) {
            int search = target - nums[i];
            if (index_map.count(search)) {
                return vector<int>{index_map[search], i};
            } else {
                index_map[nums[i]] = i;
            }
        }
        return vector<int>();
    }
};


// ANSWER
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};