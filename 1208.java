class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int[] costs = new int[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            int cost = Math.abs(s.charAt(i) - t.charAt(i));
            costs[i] = cost;
        }
        int l = 0, r = 0;
        int curCost = 0;
        int retLength = 0;
        while (r < s.length()) {
            curCost += costs[r];
            while (curCost > maxCost) {
                curCost -= costs[l];
                l ++;
            }
            retLength = Math.max(retLength, r - l + 1);
            r ++;
        }
        return retLength;
    }
}