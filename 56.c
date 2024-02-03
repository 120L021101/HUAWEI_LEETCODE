/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(void * a, void * b) {
    return **(int **)a - **(int **)b;
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (!intervalsSize)
        return (int **)malloc(0);

    *returnSize = 0;
    qsort(intervals, intervalsSize, sizeof(int *), cmp);
    int ** answer = (int **)malloc(sizeof(int *) * intervalsSize);
    int last_end = intervals[0][1];
    int last_start = intervals[0][0];
    for (int i = 1; i < intervalsSize; ++i) {
        int this_start = intervals[i][0];
        int this_end = intervals[i][1];
        if (this_start <= last_end) {
            last_end = this_end > last_end ? this_end : last_end;
        }
        else {
            answer[*returnSize] = (int *)malloc(sizeof(int) * 2);
            answer[*returnSize][0] = last_start;
            answer[*returnSize][1] = last_end;
            (*returnSize) ++;
            last_start = this_start;
            last_end = this_end;
        }
    }
    answer[*returnSize] = (int *)malloc(sizeof(int) * 2);
    answer[*returnSize][0] = last_start;
    answer[*returnSize][1] = last_end;
    (*returnSize) ++;
    answer = (int **)realloc(answer, sizeof(int *) * (*returnSize));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; ++i) {
        (*returnColumnSizes)[i] = 2;
    }
    return answer;
}