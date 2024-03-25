class Solution {

    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length][amount + 1];
        int init_amount = 0;
        while (init_amount <= amount) {
            dp[0][init_amount] = 1;
            init_amount += coins[0];
        }
        for (int i = 1; i < coins.length; ++i) {
            for (int j = 0; j <= amount; ++j) {
                int p = j;
                while (p >= 0) {
                    dp[i][j] += dp[i - 1][p];
                    p -= coins[i];
                }
            }
        }
        // for (int i = 0; i < coins.length; ++i) {
        //     for (int j = 0; j <= amount; ++j) {
        //         System.out.print(String.format("%d ", dp[i][j]));
        //     }
        //     System.out.println("");
        // }
        return dp[coins.length - 1][amount];
    }
}