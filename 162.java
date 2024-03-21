class Solution {
    public int findPeakElement(int[] nums) {
        int l = 0, r = nums.length;
        while (l < r) {
            int m = (l + r) / 2;
            boolean rightOk = (m + 1 == nums.length) || nums[m] > nums[m + 1];
            boolean leftOk = (m == 0) || (nums[m] > nums[m - 1]);
            if (rightOk && leftOk) {
                return m;
            }
            if (!rightOk) { l = m + 1; continue; }
            if (!leftOk) { r = m - 1; continue; }
        }
        return l;
    }
}