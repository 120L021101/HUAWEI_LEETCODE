class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i)
            dp[i] = -1;
        for(int i = 1; i <= amount; ++i)
            for(int j = 0; j < coins.length; ++j){
                if(i - coins[j] < 0) continue;
                if(dp[i - coins[j]] == -1) continue;
                if(dp[i] == -1) 
                    dp[i] = 1 + dp[i - coins[j]];
                else
                    dp[i] = Math.min(dp[i], 1 + dp[i - coins[j]]);
            }
        return dp[amount];
    }
}