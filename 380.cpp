class RandomizedSet {
private:
    unordered_map<int, int> hash_map;
    vector<int> nums;
public:
    RandomizedSet() {
        srand(time(NULL));
    }
    
    bool insert(int val) {
        if (hash_map.count(val)) {
            return false;
        }
        int length = nums.size();
        nums.push_back(val);
        hash_map[val] = length;
        return true;
    }
    
    bool remove(int val) {
        if (!hash_map.count(val)) {
            return false;
        }
        int idx = hash_map[val];
        nums[idx] = nums.back();
        nums.pop_back();
        hash_map[nums[idx]] = idx;
        hash_map.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */