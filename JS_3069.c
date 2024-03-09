/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int arr1[numsSize], arr1_size = 0;
    int arr2[numsSize], arr2_size = 0;
    arr1[arr1_size++] = nums[0];
    arr2[arr2_size++] = nums[1];
    for (int i = 2; i < numsSize; ++i) {
        if (arr1[arr1_size - 1] > arr2[arr2_size - 1])
            arr1[arr1_size ++] = nums[i];
        else 
            arr2[arr2_size ++] = nums[i];
    }
    int p = 0;
    for (int i = 0; i < arr1_size; ++i)
        nums[p ++] = arr1[i];
    for (int i = 0; i < arr2_size; ++i)
        nums[p ++] = arr2[i];
    return nums;
}