typedef long long int LLI;

int main(void) {
    char * buf[100];
    scanf("%s", buf);
    LLI length = strlen(buf);
    LLI tail_val = buf[length - 1] - '0';
    printf("%d", (10 - tail_val) % 10);
}