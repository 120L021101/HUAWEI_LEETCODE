char* lastNonEmptyString(char* s) {
    long long count[26] = { 0 };
    int length = strlen(s);
    for (int i = 0; i < length; ++i) {
        count[s[i] - 'a'] ++;
    }
    long long max = count[0];
    for (int i = 1; i < 26; ++i) {
        max = fmax(max, count[i]);
    }
    int rlength = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i] == max) {
            count[i] = 1;
            rlength ++;
        } else {
            count[i] = 0;
        }
    }
    char * rStr = (char *)malloc(sizeof(char) * (rlength + 1));
    rStr[rlength] = '\0';
    int pointer = rlength - 1;
    for (int i = length - 1; i >= 0 && pointer >= 0; i --){
        if (!count[s[i] - 'a']) continue;
        rStr[pointer --] = s[i];
        count[s[i] - 'a'] = 0;
    }
    return rStr;
}