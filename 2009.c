
int cmp(void * a, void * b) {
    int * int_a = (int *)a;
    int * int_b = (int *)b;
    if (*int_a > *int_b) {
        return 1;
    }
    if (*int_a == *int_b) {
        return 0;
    }
    return -1;
}

int minOperations(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);  
    int slower = 1, faster = 1;
    while (faster != numsSize) {
        if (nums[faster] == nums[slower - 1]) {
            faster ++;
            continue;
        }
        nums[slower ++] = nums[faster ++];
    }
    
    int windowSize = numsSize - 1;

    numsSize = slower;
    int left = 0, right = 0;
    int maxVal = 0;
    while (right < numsSize) {
        int diff;
        while ((diff = nums[right] - nums[left]) > windowSize) {
            left ++;
        }
        maxVal = fmax(maxVal, right - left + 1);
        right ++;
    }
    return windowSize + 1 - maxVal;
}