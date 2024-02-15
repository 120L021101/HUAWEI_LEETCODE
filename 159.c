int lengthOfLongestSubstringTwoDistinct(char* s) {
    int last_occur1 = -1, last_occur2 = -1;
    char occur1 = 0, occur2 = 0;
    int max_length = 0, current_length = 0, current_start = 0;
    int length = strlen(s);
    for (int i = 0; i != length; ++i) {
        if (occur1 == s[i]) {
            last_occur1 = i;
        }
        else if (occur2 == s[i]) {
            last_occur2 = i;
        }
        else if (last_occur1 == -1) {
            occur1 = s[i];
            last_occur1 = i;
        }
        else if (last_occur2 == -1) {
            occur2 = s[i];
            last_occur2 = i;
        }
        else {
            if (last_occur1 < last_occur2) {
                current_length -= last_occur1 - current_start + 1;
                current_start = last_occur1 + 1;
                last_occur1 = i;
                occur1 = s[i];
            } else {
                current_length -= last_occur2 - current_start + 1;
                current_start = last_occur2 + 1;
                last_occur2 = i;
                occur2 = s[i];
            }
        }
        if (++current_length > max_length) {
            max_length = current_length;
        }
    }
    if (current_length > max_length) {
        max_length = current_length;
    }
    return max_length;
}