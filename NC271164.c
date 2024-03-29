#include <stdio.h>

int construct_n(char * buf, int * idx, int n, char c) {
    buf[(*idx) ++] = c;
    int constructed_num = 0;
    int add_once = 1;
    while (constructed_num + add_once <= n) {
        constructed_num += add_once;
        buf[(*idx) ++] = c;
        add_once ++;
    }
    return n - constructed_num;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    char str[n + 1];
    str[n] = '\0';
    char c = 'a';
    int idx = 0;
    while (m) {
        m = construct_n(str, &idx, m, c);
        c ++;
        if (c == 'z' + 1) c = 'a';
    }
    while (idx != n) {
        str[idx ++] = c ++;
        if (c == 'z' + 1) c = 'a';
    }
    puts(str);
    return 0;
}