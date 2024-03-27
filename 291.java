import java.util.HashMap;
import java.util.Map;

class Solution {
    private boolean dfs(String s, int idx1, String pattern, int idx2, Map<Character, String> f1, Map<String, Character> f2) {
        if (idx1 == s.length() && idx2 == pattern.length()) {
            return true;
        }
        if (idx1 == s.length() || idx2 == pattern.length()) {
            return false;
        }
        Character p_key = pattern.charAt(idx2);
        if (f1.containsKey(p_key)) {
            String f_s = f1.get(p_key);
            for (int i = 0; i < f_s.length() && idx1 < s.length(); ++i) {
                if (f_s.charAt(i) != s.charAt(idx1))
                    return false;
                idx1 ++;
            }
            return dfs(s, idx1, pattern, idx2 + 1, f1, f2);
        } else {
            StringBuilder sb = new StringBuilder();
            while (idx1 < s.length()) {
                sb.append(s.charAt(idx1));
                idx1 ++;
                String f_s = sb.toString();
                if (f2.containsKey(f_s) && f2.get(f_s) != p_key) {
                    continue;
                }
                f1.put(p_key, f_s);
                f2.put(f_s, p_key);
                if (dfs(s, idx1, pattern, idx2 + 1, f1, f2))
                    return true;
                f1.remove(p_key);
                f2.remove(f_s);
            }
            return false;
        }
    }
    public boolean wordPatternMatch(String pattern, String s) {
        return dfs(s, 0, pattern, 0, new HashMap<>(), new HashMap<>());
    }
}