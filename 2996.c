#define MAXSIZE 100
int missingInteger(int* nums, int numsSize) {
    unsigned char occur[100] = { 0 };
    for (int i = 0; i < numsSize; ++i) {
        occur[nums[i]] = 1;
    }    
    int pointer = 1, sum = nums[0];
    while (pointer != numsSize && nums[pointer] == nums[pointer - 1] + 1) {
        sum += nums[pointer];
        pointer ++;
    }
    while (sum < MAXSIZE && occur[sum]) sum ++;
    return sum;
}