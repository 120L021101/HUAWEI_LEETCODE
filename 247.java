import java.util.Arrays;
import java.util.LinkedList;

class Solution {
    private void dfs(List<String> ans, StringBuilder current, List<Character> available, int i, int n, int m, int a) {
        if (i == n) {
            if (a != 1 && current.charAt(0) == '0') return;
            if (a == 1 && (current.charAt(0) == '6' || current.charAt(0) == '9')) return;
            StringBuilder addStr = new StringBuilder(current.toString());
            for (int p = current.length() - 1 - m; p >= 0; --p) {
                if (current.charAt(p) == '6') {
                    addStr.append('9');
                }
                else if (current.charAt(p) == '9') {
                    addStr.append('6');
                }
                else
                    addStr.append(current.charAt(p));
            }
            ans.add(addStr.toString());
            return ;
        }
        for (Character ch : available) {
            current.append(ch);
            dfs(ans, current, available, i + 1, n, m, a);
            current.deleteCharAt(current.length() - 1);
        }
        return ;
    }
    public List<String> findStrobogrammatic(int n) {
        List<String> ans = new LinkedList<>();
        dfs(ans, new StringBuilder(), new LinkedList<>(Arrays.asList('0', '1', '6', '8', '9')), 0, (n + 1) / 2, n % 2, n);
        return ans;
    }
}