import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
    public List<List<Integer>> findMissingRanges(int[] nums, int lower, int upper) {
        if (nums.length == 0) {
            return Arrays.asList(Arrays.asList(lower, upper));
        }
        List<List<Integer>> retList = new LinkedList<>();
        if (nums[0] > lower) {
            retList.add(Arrays.asList(lower, nums[0] - 1));
        }
        int f = 0, s = 1;
        while (s < nums.length) {
            if (nums[f] != nums[s] - 1) {
                retList.add(Arrays.asList(nums[f] + 1, nums[s] - 1));
            }
            f += 1;
            s += 1;
        }
        if (nums[nums.length - 1] < upper) {
            retList.add(Arrays.asList(nums[nums.length - 1] + 1, upper));
        }
        return retList;
    }
}