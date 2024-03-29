class Solution {
    public int minimumSum(int[] nums) {
        Integer minCost = null;
        for(int i = 0; i < nums.length - 2; ++i) {
            for (int j = i + 2; j < nums.length; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    if (nums[k] > Math.max(nums[i], nums[j])) {
                        if (minCost == null) {
                            minCost = nums[i] + nums[j] + nums[k];
                        }
                        minCost = Math.min(nums[i] + nums[j] + nums[k], minCost);
                    }                    
                }
            }
        }
        if (minCost == null) return -1;
        return minCost;
    }
}