int minOperations(int* nums, int numsSize, int k) {
    int current = 0;
    for (int i = 0; i < numsSize; ++i) {
        current ^= nums[i];
    }
    int diff = current ^ k;
    int count = 0;
    while (diff) {
        count += diff % 2;
        diff >>= 1;
    }
    return count;
}