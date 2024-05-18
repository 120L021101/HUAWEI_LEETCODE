class Solution {
    public int maxDivScore(int[] nums, int[] divisors) {
        int[] scores = new int[divisors.length];
        for (int i = 0; i < nums.length; ++i) {
            for (int j = 0; j < divisors.length; ++j) {
                if (nums[i] % divisors[j] == 0) {
                    scores[j] += 1;
                }
            }
        }
        int max_idx = 0;
        for (int i = 1; i < scores.length; ++i) {
            if (scores[i] > scores[max_idx]) {
                max_idx = i;
            }
            else if (scores[i] == scores[max_idx] && divisors[i] < divisors[max_idx]) {
                max_idx = i;
            }
        }
        return divisors[max_idx];
    }
}