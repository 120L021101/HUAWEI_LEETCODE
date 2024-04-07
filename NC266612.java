import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        
        int start_idx = str.indexOf('1');
        if (-1 == start_idx) {
            System.out.println(0);
            sc.close();
            return;
        }

        int maxScore = 0, cur = 0;
        for (int i = str.length() - 1; i > start_idx; --i) {
            if (str.charAt(i) == '0') {
                cur --;
            } else {
                cur ++;
            }
            maxScore = Math.max(maxScore, cur);
        }
        int score = 1 + maxScore;
        System.out.println(score);

        sc.close();
    }
}
