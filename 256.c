#define min(a, b) (a < b ? a : b)
int minCost(int** costs, int costsSize, int* costsColSize) {
    int dp[costsSize][3];
    memset(dp, 0, sizeof(int) * 3 * (costsSize));
    memcpy(dp[0], costs[0], sizeof(int) * 3);
    for (int i = 1; i != costsSize; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + costs[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + costs[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + costs[i][2];
    }
    return min(
        min(dp[costsSize - 1][0], dp[costsSize - 1][1]),
        dp[costsSize - 1][2]
    );
}