#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    char buf[n + 1];
    scanf("%s", buf);
    if (buf[0] > buf[n - 1])
        putchar(buf[0]);
    else
        putchar(buf[n - 1]);
    return 0;
}