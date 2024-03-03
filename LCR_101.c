
bool canPartition(int* nums, int numsSize){
    int sum_val = 0, max_val = -1;
    for (int i = 0; i < numsSize; ++i) {
        sum_val += nums[i];
        max_val = fmax(max_val, nums[i]);
    }
    if (numsSize == 1) return false;
    if (sum_val % 2 == 1) return false;
    if ((max_val << 1) > sum_val) return false;
    int target = sum_val >> 1;
    unsigned char dp[1 + target];
    memset(dp, 0, sizeof(unsigned char) * (target + 1));
    dp[nums[0]] = 1;
    for (int i = 1; i != numsSize; ++i) {
        for (int j = target; j != -1; --j) {
            if (j > nums[i]) {
                dp[j] |= dp[j - nums[i]];
            }
        }
    }
    return dp[target];
}