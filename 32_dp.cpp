class Solution {
public:
    int longestValidParentheses(string s) {
        int dp [s.length() + 1];
        fill(dp, dp + s.length(), 0);
        int max_value = 0;
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == '(') 
                continue;
            if (s[i - 1] == '(') {
                dp[i] = (i - 2) >= 0 ? (dp[i - 2] + 2) : 2;
            }
            else {
                int index = i - 1 - dp[i - 1];
                char dp_left_end = index >= 0 ? s[index] : ')';
                if (dp_left_end == '(') {
                    dp[i] = (index - 1 >= 0 ? dp[index - 1] : 0) + 2 + dp[i - 1];
                }
            }
            max_value = max(max_value, dp[i]);
        }
        // copy(dp, dp + s.length(), ostream_iterator<int>(cout, "\t"));
        return max_value;
    }
};