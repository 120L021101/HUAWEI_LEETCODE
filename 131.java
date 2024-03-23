
class Solution {
    private void dfs(int idx, String s, boolean[][] dp,  List<String> path, List<List<String>> retAns) {
        if (idx == s.length()) {
            List<String> copy = new LinkedList<>();
            copy.addAll(path);
            retAns.add(copy);
            return;
        }
        for (int end = idx; end < s.length(); ++end) {
            if (!dp[idx][end]) continue;
            path.add(s.substring(idx, end + 1));
            dfs(end + 1, s, dp, path, retAns);
            path.remove(path.size() - 1);
        }
    }
    public List<List<String>> partition(String s) {
        List<List<String>> retAns = new LinkedList<>();
        boolean[][] dp = new boolean[s.length()][s.length()];
        for (int i = 0; i < dp.length; ++i) {
            for (int j = 0; j < dp.length; ++j) {
                dp[i][j] = false;
            }
            dp[i][i] = true;
        }
        for (int i = dp.length - 1; i >= 0; --i) {
            for (int j = i + 1; j < dp.length; ++j) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (i == j - 1 || dp[i + 1][j - 1]);
            }
        }
        List<String> path = new ArrayList<>();
        dfs(0, s, dp, path, retAns);
        return retAns;
    }
}