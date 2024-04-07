import java.util.Arrays;
import java.util.Scanner;
import java.util.function.DoubleToLongFunction;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer n = sc.nextInt();
        Integer k = sc.nextInt();

        Long[] arr = new Long[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextLong();
        }

        Arrays.sort(arr, (a, b) -> {
            if (a > b) return -1;
            if (a < b) return 1;
            return 0;
        });

        Long result = Long.valueOf(1);
        for (int i = 0; i <= k; ++i) {
            result *= arr[i];
            result %= Long.valueOf(1000000007);
        }
        result += k;
        for (int i = k + 1; i < n; ++i) {
            result += arr[i];
            result %= Long.valueOf(1000000007);
        }
        System.out.println(result);
        sc.close();
    }
}
