#include <stdio.h>

int main(void) {
    char buf[200001];
    scanf("%s", buf);
    long long int countOp = 0;
    unsigned char beforeChar = 0;
    char * p = buf;
    char ch;
    while ((ch = *p) != '\0') {
        if ('a' <= ch && ch <= 'z') {
            beforeChar = ch;
            p ++;
        }
        else if ('A' <= ch && ch <= 'Z') {
            if (beforeChar == ' ' || beforeChar == 0) {
                beforeChar = ch;
            }
            else {
                beforeChar = ' ';
                countOp ++;
            }
            p ++;
        }
    }
    printf("%lld", countOp);
    return 0;
}