import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Main {
    private static final long LOG = (long)(1e9 + 7);
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i != n; ++i) {
            arr[i] = sc.nextLong();
        }
        Arrays.sort(arr);
        int remaining = n - k;
        long[][] dp = new long[n][remaining + 1];
        for (int i = 0; i < n; ++i) {
            dp[i][1] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (0 != (arr[i] % arr[j]))
                    continue;
                for (int p = 2; p <= remaining; ++p) {
                    dp[i][p] += dp[j][p - 1];
                    dp[i][p] %= LOG;
                }
            }
        }
        long res = 0;
        for (int i = 0; i < n; ++i) {
            res += dp[i][remaining];
            res %= LOG;
        }
        System.out.println(res);
        sc.close();
    }
}
