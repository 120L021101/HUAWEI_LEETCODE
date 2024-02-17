#define FXY(i, j) (i * numsSize + j)

int memorySearch(int* nums, int numsSize, int start, int end, int target, int * memory) {
    if (start >= end) {
        return 0;
    }
    int idx = FXY(start, end);
    if (memory[idx]) return memory[idx];
    int op1 = 0, op2 = 0, op3 = 0;
    if (nums[start] + nums[start + 1] == target) {
        op1 = memorySearch(nums, numsSize, start + 2, end, target, memory) + 1;
    }
    if (nums[start] + nums[end] == target) {
        op2 = memorySearch(nums, numsSize, start + 1, end - 1, target, memory) + 1;
    }
    if (nums[end - 1] + nums[end] == target) {
        op3 = memorySearch(nums, numsSize, start, end - 2, target, memory) + 1;
    }
    int max_op = 0;
    max_op = fmax(op1, op2);
    max_op = fmax(max_op, op3);
    // printf("%d %d %d %d\n", start, end, target, max_op);
    return memory[idx] = max_op;
}

int maxOperations(int* nums, int numsSize) {
    puts("call");
    int memory[numsSize][numsSize];
    int target1 = nums[0] + nums[1];
    int target2 = nums[0] + nums[numsSize - 1];
    int target3 = nums[numsSize - 1] + nums[numsSize - 2];
    memset(memory, 0, sizeof(int) * numsSize * numsSize);
    int op1 = memorySearch(nums, numsSize, 2, numsSize - 1, target1, memory);
    memset(memory, 0, sizeof(int) * numsSize * numsSize);
    int op2 = memorySearch(nums, numsSize, 1, numsSize - 2, target2, memory);
    memset(memory, 0, sizeof(int) * numsSize * numsSize);
    int op3 = memorySearch(nums, numsSize, 0, numsSize - 3, target3, memory );
    return fmax(op1, fmax(op2, op3)) + 1;
}