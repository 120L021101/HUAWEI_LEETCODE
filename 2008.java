import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

class Solution {
    public long maxTaxiEarnings(int n, int[][] rides) {
        Map<Integer, List<int[]>> earning = new HashMap<>();
        for (int[] ride : rides) {
            int start = ride[0], end = ride[1], tip = ride[2];
            if (!earning.containsKey(end)) {
                earning.put(end, new LinkedList<>());
            }
            earning.get(end).add(new int[] {start, end - start + tip});
        }
        long[] dp = new long[n + 1];
        long maxEarning = 0;
        for (int i = 1; i < dp.length; ++i) {
            dp[i] = dp[i - 1];
            if (!earning.containsKey(i))
                continue;
            for (int[] startAndEarning : earning.get(i)) {
                int start = startAndEarning[0]; int earn = startAndEarning[1];
                dp[i] = Math.max(dp[i], dp[start] + earn);
            }
            maxEarning = Math.max(dp[i], maxEarning);
        } 
        return maxEarning;
    }
}