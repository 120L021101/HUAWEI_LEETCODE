import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Map;

class Solution {
    private void dfs(Map<Character, Integer> countMap, StringBuilder current, String s, List<String> strings) {
        if (2 * current.length() == s.length()) {
            StringBuilder sb = new StringBuilder(current.toString());
            for (int i = current.length() - 1; i >= 0; --i) {
                sb.append(current.charAt(i));
            }
            strings.add(sb.toString());
            return;
        }
        if (2 * current.length() == s.length() - 1) {
            StringBuilder sb = new StringBuilder(current.toString());
            for (Character ch : countMap.keySet()) {
                if (countMap.get(ch) == 1) {
                    sb.append(ch);
                    break;
                }
            }
            for (int i = current.length() - 1; i >= 0; --i) {
                sb.append(current.charAt(i));
            }
            strings.add(sb.toString());
            return;
        }
        for (Character ch : countMap.keySet()) {
            if (countMap.get(ch) >= 2) {
                countMap.put(ch, countMap.get(ch) - 2);
                current.append(ch);
                dfs(countMap, current, s, strings);
                current.delete(current.length() - 1, current.length());
                countMap.put(ch, countMap.get(ch) + 2);
            }
        }
    }
    public List<String> generatePalindromes(String s) {
        Map<Character, Integer> countMap = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            countMap.put(s.charAt(i), countMap.getOrDefault(s.charAt(i), 0) + 1);
        }
        int oddVal = 0;
        for (Integer num : countMap.values()) {
            if (num % 2 == 1) {
                oddVal ++;
            }
            if (oddVal == 2) return new ArrayList<String>();
        }
        List<String> strings = new LinkedList<>();
        dfs(countMap, new StringBuilder(), s, strings);
        return strings;
    }
}