

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static char ** output;
static const char* str;
static char* current;
static unsigned int size;

void recursion(unsigned char depth, unsigned short available) {
    if (!available)
        memcpy(*output++, current, size);

    unsigned int pick, this_available = available;
    unsigned char digit, cp;
    while (this_available) {
        pick = this_available & (-this_available);
        this_available ^= pick;

        digit = 0; cp = pick;
        while (cp >>= 1)
            digit ++;
        
        current[depth] = str[digit];
        recursion(depth - 1, available ^ pick);
    }
}

char** permutation(char* S, int* returnSize){
    int S_length = strlen(S);
    char buf[S_length + 1];
    buf[S_length] = '\0';
    current = buf;
    str = S; 
    size = sizeof(char) * (S_length + 1);
 
    int rs = 1;
    for (int i = 2; i <= S_length; ++i)
        rs *= i;
    *returnSize = rs;

    char **answer = (char **)malloc(sizeof(char *) * (*returnSize));
    output = answer;
    for (char **p = answer, **end = answer + *returnSize; \
            p != end; ++p) {
        *p = (char *)malloc(size);
    }    
    recursion(S_length - 1, (0x1 << S_length) - 1);


    output = NULL;
    str = NULL;
    current = NULL;
    size = 0;

    return answer;
}
