import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> valMap = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            int num = nums[i];
            if (valMap.containsKey(target - num)) {
                return new int[] { valMap.get(target - num), i };
            }
            valMap.put(nums[i], i);
        }
        return new int[] {};
    }
}