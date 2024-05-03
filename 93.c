/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


static char * buf;
static size_t buf_length;

bool is_legal(char *s, int start, int end) {
    if (start == end) {
        return false;
    }
    if (s[start] == '0') {
        return end == start + 1;
    }
    // 一位数
    if (end == start + 1) {
        return true;
    }
    // 两位数
    if (end == start + 2) {
        return true;
    }
    // 三位数
    if (end == start + 3) {
        if (s[start] == '1') {
            return true;
        }
        if (s[start] != '2') {
            return false;
        }
        if (s[start + 1] >= '6') {
            return false;
        }
        if (s[start + 1] < '5') { 
            return true;
        }
        return s[start + 2] <= '5'; // 255
    }
    // 更多位数
    return false;
}

static char** retAns;
static const int maxSize = 100;

void dfs_check(char * write_p, char* s, int length, int idx, int idx_ls[0], int cnt, int *returnSize) {
    if (cnt == 3) {
        if (is_legal(s, idx, length)) {
            for (int i = idx; i < length; ++i) {
                write_p[i - idx] = s[i];
            }
            retAns[*returnSize] = (char *)malloc(sizeof(char) * (buf_length + 1));
            strcpy(retAns[*returnSize], buf);
            *returnSize += 1;
        }
        return ;
    }
    int s_idx = idx + 1;
    while (s_idx < length && is_legal(s, idx, s_idx)) {
        idx_ls[cnt] = s_idx;
        int i;
        for (i = idx; i < s_idx; ++i) {
            write_p[i - idx] = s[i];
        }
        write_p[i - idx] = '.';
        dfs_check(write_p + s_idx - idx + 1, s, length, s_idx, idx_ls, cnt + 1, returnSize);
        s_idx += 1;
    }
}

char** restoreIpAddresses(char* s, int* returnSize) {
    buf = (char *)malloc(sizeof(char) * (strlen(s) + 3 + 1));
    buf_length = strlen(s) + 3;
    buf[buf_length] = '\0';
    *returnSize = 0;

    retAns = (char **)malloc(sizeof(char *) * maxSize);

    int idx_ls[3];

    dfs_check(buf, s, strlen(s), 0, idx_ls, 0, returnSize);

    free(buf);
    return retAns;
}