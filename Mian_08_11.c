int waysToChange(int n){
    unsigned int memory_used_size = sizeof(int) * 27;
    int dp[27];
    memset(dp, 0, memory_used_size);
    dp[1] = 1; dp[0] = 1;
    for (int i = 2; i <= 25; ++i) {
        dp[i] = dp[i - 1];
        if (i < 5) continue;
        dp[i] += dp[i - 5] + dp[5];
        if (i < 10) continue;
        dp[i] += dp[i - 10] + dp[10];
        if (i < 25) continue;
        dp[i] += dp[i - 25] + dp[25];
    }
    for (int coin = 26; coin <= n; coin++) {
        dp[26] = dp[25] + 
    }
}
