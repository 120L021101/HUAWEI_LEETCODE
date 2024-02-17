int maxOperations(int* nums, int numsSize) {
    numsSize -= numsSize % 2;
    int pointer = 2;
    int prevScore = nums[0] + nums[1];
    while (pointer < numsSize) {
        int score = nums[pointer] + nums[pointer + 1];
        if (score != prevScore)
            break;
        pointer += 2;
    }
    return pointer / 2;
}