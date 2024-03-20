class Solution {
    public String longestPalindrome(String s) {
        boolean[][] dp = new boolean[s.length()][s.length()];
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = true;
        }
        int maxLength = 0;
        String retStr = s.substring(0, 1);
        for (int i = s.length() - 1; i >= 0; --i) {
            for (int j = i + 1; j < s.length(); ++j) {
                dp[i][j] = s.charAt(i) == s.charAt(j) && (dp[i + 1][j - 1] || i == j - 1);
                if (dp[i][j] && (j - i + 1) > maxLength) {
                    maxLength = j - i + 1;
                    retStr = s.substring(i, j + 1);
                }
            }
        }
        return retStr;
    }
}