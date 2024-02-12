class Solution {
public:
    int waysToChange(int n) {
        int dp_5[27] = { 0 };
        int dp_10[27] = { 0 };
        int dp_25[27] = { 0 };

        for (int i = 5; i != 26; ++i) {
            dp_5[i] = dp_5[i - 5] + 1;
            if (i < 10) continue;
            dp_10[i] = dp_10[i - 10] + dp_5[i - 10] + 1;
            if (i < 25) continue;
            dp_25[i] = dp_25[i - 25] + dp_10[i - 25] + dp_5[i - 25] + 1;
        }

        if (n < 26) {
            return 1 + dp_5[n] + dp_10[n] + dp_25[n];
        }

        for (int i = 25; i != n; ++i) {
            dp_5[26] = (dp_5[21] + 1) % 1000000007;
            dp_10[26] = (dp_10[16] + dp_5[16] + 1) % 1000000007;
            dp_25[26] = (dp_25[1] + dp_10[1] + dp_5[1] + 1) % 1000000007; 
            memmove(dp_5, dp_5 + 1, sizeof(int) * 26);
            memmove(dp_10, dp_10 + 1, sizeof(int) * 26);
            memmove(dp_25, dp_25 + 1, sizeof(int) * 26);
        }
        return (dp_25[26] + dp_10[26] + dp_5[26] +1) % 1000000007;
    }
};