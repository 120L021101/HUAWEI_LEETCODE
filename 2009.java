import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public int minOperations(int[] nums) {
        Set<Integer> dedupNums = new HashSet<>();
        for (int num : nums) {
            dedupNums.add(num);
        }
        List<Integer> sortedNums = new ArrayList<>();
        for (int dedupNum : dedupNums) {
            sortedNums.add(dedupNum);
        }
        Collections.sort(sortedNums);

        int windowSize = nums.length - 1;
        int left = 0, right = 0;
        int maxNums = 0;
        while (right < sortedNums.size()) {
            int diff;
            while ((diff = sortedNums.get(right) - sortedNums.get(left)) > windowSize) {
                left ++;
            }
            maxNums = Math.max(maxNums, right - left + 1);
            right ++;
        }
        return nums.length - maxNums;
    }
}