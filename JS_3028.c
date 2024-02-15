int returnToBoundaryCount(int* nums, int numsSize) {
    int prefix[numsSize];
    prefix[0] = nums[0];
    int c = 0;
    for (int i = 1; i != numsSize; ++i) {
        prefix[i] = prefix[i - 1] + nums[i];
        if (!prefix[i])
            c++;
    }
    return c;
}