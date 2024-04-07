import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = sc.nextLong();
        }

        Set<Long> occured = new HashSet<>();
        boolean isLegal = true;
        for (int i = 0; i < n; ++i) {
            if (arr[i] > n) {
                isLegal = false;
                break;
            }
            if (occured.contains(arr[i])) {
                isLegal = false;
                break;
            }
            occured.add(arr[i]);
        }
        if (!isLegal) {
            System.out.println(0);
        } else {
            System.out.println(1);
            System.out.println(String.format("%d %d", 1, arr[0] + 1));
        }

        sc.close();
    }
}
