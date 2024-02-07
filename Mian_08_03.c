int findMagicIndex(int* nums, int numsSize){
    int i = 0;
    while (i < numsSize) {
        if (i == nums[i]) {
            return i;
        }
        if (i > nums[i]) {
            i ++;
        }
        else {
            i = nums[i];
        }
    }
    return -1;
}
