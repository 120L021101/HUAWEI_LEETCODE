import java.util.HashMap;
import java.util.Map;

class Solution {
    public boolean canPermutePalindrome(String s) {
        Map<Character, Integer> counter = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            counter.put(s.charAt(i), counter.getOrDefault(s.charAt(i), 0) + 1);
        }
        Integer odd = null;
        for (Integer val : counter.values()) {
            if (val % 2 == 1) {
                if (odd != null) {
                    return false;
                }
                odd = val;
            }
        }
        return true;
    }
}