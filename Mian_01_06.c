

char* compressString(char* S){
    int length = strlen(S);
    if (!length) return S;
    char * compress_S = (char *)malloc(sizeof(char) * (length + 1));
    memset(compress_S, 0, sizeof(char) * (length + 1));
    char* end1 = S + length;
    char* end2 = compress_S + length;
    
    char* pointer1 = S, *pointer2 = compress_S;
    *pointer2 = *pointer1;
    int count = 0;
    while (pointer1 <= end1) {
        if (pointer1 != end1 && *pointer1 == *pointer2) {
            count ++;
            pointer1 ++;
        }
        else {
            if (++pointer2 == end2) {
                free(compress_S);
                return S;
            }
            sprintf(pointer2, "%d", count);
            while (*pointer2) pointer2++;
            if (pointer2 == end2) {
                free(compress_S);
                return S;
            }
            if (pointer1 == end1) {
                *pointer2 = '\0';
                return compress_S;
            }
            *pointer2 = *pointer1;
            pointer1 ++;
            count = 1;
        }
    }
    return NULL;
}
