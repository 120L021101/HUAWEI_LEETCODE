import java.util.HashMap;
import java.util.Map;

class Solution {
    public String minWindow(String s, String t) {
        Map<Character, Integer> counter = new HashMap<>();
        Map<Character, Integer> counter_t = new HashMap<>();
        for (int i = 0; i < t.length(); ++i) {
            counter_t.put(t.charAt(i), counter_t.getOrDefault(t.charAt(i), 0) + 1);
        }
        int l = 0, r = 0;
        int collect = 0;
        int minW = Integer.MAX_VALUE, minL = 0, minR = 0;
        while (r < s.length()) {
            if (!counter_t.containsKey(s.charAt(r))) {
                r ++;
                continue;
            }
            counter.put(s.charAt(r), counter.getOrDefault(s.charAt(r), 0) + 1);
            if (counter.get(s.charAt(r)) <= counter_t.get(s.charAt(r)) ) {
                collect ++;
            }
            if (collect == t.length()) {
                while (true) {
                    if (!counter_t.containsKey(s.charAt(l))) {
                        l ++;
                        continue;
                    }
                    if (counter.get(s.charAt(l)).equals(counter_t.get(s.charAt(l)))) {
                        break;
                    }
                    counter.put(s.charAt(l), counter.get(s.charAt(l)) - 1);
                    l ++;
                }
                int curW = r - l + 1;
                if (curW < minW) {
                    minW = curW;
                    minL = l;
                    minR = r;
                }

                counter.put(s.charAt(l), counter.get(s.charAt(l)) - 1);
                collect -= 1;
                l ++;
            }
            r ++;
        }
        if (minW == Integer.MAX_VALUE) {
            return "";
        }
        return s.substring(minL, minR + 1);
    }
}