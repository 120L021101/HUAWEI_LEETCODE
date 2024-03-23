int missingNumber(int* nums, int numsSize) {
    int expect = numsSize;
    int actual = 0;
    for (int i = 0; i < numsSize; ++i) {
        expect ^= i;
        actual ^= nums[i];
    }
    return actual ^ expect;
}