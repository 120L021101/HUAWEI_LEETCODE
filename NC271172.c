#include <stdio.h>

int main(void) {
    char n[200000];
    scanf("%s", &n);
    int length = strlen(n);
    int count = 0;
    int C = 0;
    for (int i = 0; i < length; ++i) {
        int num = n[i] - '0';
        if ((C + num) % 9 == 0) {
            count += 1;
        }
        C = (C + num) % 9;
        C *= 10;
    }
    printf("%d", count);
    return 0;
}