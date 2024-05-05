/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    *returnSize = codeSize;
    int* retCode = (int *)malloc(sizeof(int) * codeSize);
    memset(retCode, 0, sizeof(int) * codeSize);
    if (k == 0) {
        return retCode;
    }
    int left, right;
    if (k > 0) {
        left = 1;
    }
    if (k < 0) {
        left = codeSize + k;
    }
    right = left;

    int window_sum = 0;

    for (int i = 0; i < abs(k); ++i) {
        window_sum += code[right];
        right = (right + 1) % codeSize;
    }
    for (int i = 0; i < codeSize; ++i) {
        retCode[i] = window_sum;
        window_sum -= code[left];
        window_sum += code[right];

        left = (left + 1) % codeSize;
        right = (right + 1) % codeSize;
    }

    return retCode;
}