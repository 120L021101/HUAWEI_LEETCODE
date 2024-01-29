#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[s.length()][s.length()];
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < s.length(); ++j) {
                dp[i][j] = false;
            }
        }
        int max_value = 0, r_s, r_e;
        for (int j = 0; j < s.length(); ++j) {
            for (int i = 0; i <= j; ++i) {
                if (i == j) {
                    dp[i][j] = true;
                }
                else if (i == j - 1) {
                    if (s[i] == s[j])
                        dp[i][j] = true;
                }
                else {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                }
                if (dp[i][j] && j - i + 1 > max_value) {
                    max_value = j - i + 1;
                    r_s = i; r_e = j + 1;
                }
            }
        }
        return s.substr(r_s, r_e - r_s);
    }
};



int main(void) {
    Solution s;
    cout << s.longestPalindrome("ABABCCC");
}