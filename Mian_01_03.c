

char* replaceSpaces(char* S, int length){
    int count_blank = 0;
    for (int i = 0; i < length; ++i) {
        if (S[i] == ' ')
            count_blank ++;
    }
    int real_end = length + count_blank * 2 - 1;
    S[real_end + 1] = '\0';
    int fake_end = length - 1;
    while (fake_end >= 0) {
        if (S[fake_end] != ' ') {
            S[real_end] = S[fake_end];
            real_end --;
            fake_end --;
            continue;
        }
        S[real_end --] = '0';
        S[real_end --] = '2';
        S[real_end --] = '%';
        fake_end --;
    }
    return S;
}
