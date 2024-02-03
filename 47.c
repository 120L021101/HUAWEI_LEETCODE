/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define alloc_size 50
void dfs(int idx, int numsSize, int* buff_available, int* visited, int * nums, int* ans_size, int* cur, int*** ans) {
    if (idx == numsSize) {
        if (!(*buff_available)) {
            *buff_available = alloc_size;
            *ans = (int **)realloc(*ans, sizeof(int *) * (*ans_size + alloc_size));
        }
        (*ans_size) ++;
        (*ans)[*ans_size - 1] = (int *)malloc(sizeof(int) * numsSize);
        memcpy((*ans)[*ans_size - 1], cur, sizeof(int) * numsSize);
        (*buff_available) --;
        return; 
    }
    for (int i = 0; i < numsSize; ++i) {
        if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]))
            continue;
        visited[i] = 1; cur[idx] = nums[i];
        dfs(idx + 1, numsSize, buff_available, visited, nums, ans_size, cur, ans);
        visited[i] = 0;
    }
}
int cmp(void * a, void * b) {
    return *(int *)a - *(int *)b;
}
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    (*returnSize) = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int** ans = (int **)malloc(0 * sizeof(int));
    int buff_available = 0;
    int* visited = (int *)calloc(numsSize, sizeof(int));
    int cur[numsSize];
    dfs(0, numsSize, &buff_available, visited, nums, returnSize, cur, &ans);
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i) (*returnColumnSizes)[i] = numsSize;
    return ans;
}