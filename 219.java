import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        if (k == 0) {
            return false;
        }
        Map<Integer, Integer> countMap = new HashMap<>();
        // init
        for (int i = 0; i < Math.min(nums.length, k); ++i) {
            int val;
            countMap.put(nums[i], val = countMap.getOrDefault(nums[i], 0) + 1);
            if (val != 1) {
                return true;
            }
        }
        int l = 0, r = k;
        while (r < nums.length) {
            int countNum = countMap.getOrDefault(nums[r], 0);
            if (countNum != 0) {
                return true;
            }
            countMap.put(nums[r], countMap.getOrDefault(nums[r], 0) + 1);
            countMap.put(nums[l], countMap.get(nums[l]) - 1);
            l ++;
            r ++;
        }
        return false;
    }
}