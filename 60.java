class Solution {
    public String getPermutation(int n, int k) {
        int Ann = 1;
        for (int i = 2; i <= n; ++i) {
            Ann *= i;
        }
        StringBuilder sb = new StringBuilder();
        boolean[] visited = new boolean[n];
        for (int i = n; i > 0; --i) {
            Ann /= i;
            int group = 0;
            while (k > Ann) {
                k -= Ann;
                group ++;
            }
            int picked_idx = 0;
            while (visited[picked_idx]) picked_idx ++;
            for (int c = 0; c < group; ++c) {
                do {
                    picked_idx = (picked_idx + 1) % n;
                } while (visited[picked_idx]);
            }
            sb.append(Integer.toString(picked_idx + 1));
            visited[picked_idx] = true;
        }
        return sb.toString();
    }
}