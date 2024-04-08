import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] findOriginalArray(int[] changed) {
        if (changed.length % 2 == 1) {
            return new int[0];
        }
        Arrays.sort(changed);
        Map<Integer, Integer> counter = new HashMap<>();
        for (int change : changed) {
            counter.put(change, counter.getOrDefault(change, 0) + 1);
        }
        int idx = 0;
        int[] originalArray = new int[changed.length / 2];
        for (int change : changed) {
            if (counter.get(change) == 0) {
                continue;
            }
            counter.put(change, counter.get(change) - 1);
            int doubledChange = 2 * change;
            if (0 == counter.getOrDefault(doubledChange, 0)) {
                return new int[0];
            }
            counter.put(doubledChange, counter.get(doubledChange) - 1);
            originalArray[idx ++] = change;
        }
        return originalArray;
    }
}