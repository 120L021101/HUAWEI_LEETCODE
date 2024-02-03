
char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char* result = (char *)calloc(len1 + len2 + 2, sizeof(char));
    
    for (int p2 = len2 - 1; p2 >= 0; p2 --) {
        char C = 0, C_r = 0;
        char val2 = num2[p2] - '0';
        int r_idx = len2 - 1 - p2;
        for (int p1 = len1 - 1; p1 >= 0; p1 --, r_idx ++) {
            char val1 = num1[p1] - '0';
            char r = (val1 * val2 + C);
            C = r / 10;
            r %= 10;
            result[r_idx] += r + C_r;
            C_r = result[r_idx] / 10;
            result[r_idx] %= 10;
        }
        result[r_idx] += C + C_r;
        if (result[r_idx] >= 10) {
            result[r_idx + 1] += 1;
            result[r_idx] %= 10;
        }
    }
    int end = len1 + len2;
    while (!result[end] && end) end--;
    result[end + 1] = '\0';
    
    for (int i = 0; i <= end; ++i) {
        result[i] += '0';
    }
    int start = 0;
    while (start < end) {
        char temp = result[end];
        result[end] = result[start];
        result[start] = temp;
        start ++;
        end --;
    }
    return result;
}