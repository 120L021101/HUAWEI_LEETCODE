class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        long acc = 0;
        long minAcc = 0; int idx = 0;
        for (int i = 0; i < gas.length; ++i) {
            acc += gas[i] - cost[i];
            if (i == 0 || acc <= minAcc) {
                idx = i + 1;
                minAcc = acc;
            }
        }
        if (acc >= 0) {
            return idx == gas.length ? 0 : idx;
        }
        return -1;
    }
}