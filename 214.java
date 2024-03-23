class Solution {
    public String shortestPalindrome(String s) {
        if (s.length() == 0) return "";
        int[] next = new int[s.length()];
        next[0] = 0;
        int i = 1, j = 0;
        while (i < s.length()) {
            while (j != 0 && s.charAt(i) != s.charAt(j)) {
                j = next[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                next[i] = ++j;
            }
            i ++;
        }
        i = s.length() - 1;
        j = 0;
        int max_j = 0;
        while (i >= 0) {
            while (j != 0 && s.charAt(i) != s.charAt(j)) {
                j = next[j - 1];
            }
            if (s.charAt(i) == s.charAt(j)) {
                if (i <= max_j)
                    max_j = Math.max(j + 1, max_j);
                j ++;
            }
            i --;
        }
        StringBuilder stringBuilder = new StringBuilder();
        for (i = 0; i < s.length() - max_j; ++i) {
            stringBuilder.append(s.charAt(s.length() - i - 1));
        }
        stringBuilder.append(s);
        return stringBuilder.toString();
    }
}