int find(int *nums, int nums_start, int length, int target) {
    int end = length - 1;
    int start = nums_start;
    while (start < end) {
        int mid = (start + end) / 2;
        int judge = nums[mid];
        if (judge < target) {
            start = mid + 1;
        } else if (judge > target) {
            end = mid - 1;
        } else {
            while (mid >= nums_start && nums[mid] == target)
                mid--;
            return mid;
        }
    }
    while (end >= nums_start && nums[end] >= target)
        end--;
    return end;
}
int cmp(void *a, void *b) {
    return *(int *)a > *(int *)b;
}
int threeSumSmaller(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int all_circumstances = 0;
    for (int i = 0; i < numsSize - 2; ++i) {
        int t1 = target - nums[i];
        for (int j = i + 1; j < numsSize - 1; ++j) {
            int t2 = t1 - nums[j];
            int k = find(nums, j + 1, numsSize, t2);
            all_circumstances += k - j;
        }
    }
    return all_circumstances;
}