#define max(a, b) (a > b ? a : b)
bool isOneEditDistance(char* s, char* t) {
    
    int s_length = strlen(s);
    int t_length = strlen(t);
    if (s_length < t_length - 1 || s_length > t_length + 1) {
        return false;
    }
    if (s_length == t_length) {
        char * s_p = s, * s_end = s + s_length;
        char * t_p = t, * t_end = t + t_length;
        bool oneChance = true;
        while (s_p != s_end && (*s_p == *t_p || oneChance)) {
            if (*s_p != *t_p) {
                oneChance = false;
            }
            s_p ++;
            t_p ++;
        }
        return !oneChance && s_p == s_end;
    }
    char * bigger_p, * bigger_end;
    char * shorter_p, * shorter_end;
    if (s_length > t_length) {
        bigger_p = s;
        shorter_p = t;
        bigger_end = s + s_length;
        shorter_end = t + t_length;
    } else {
        bigger_p = t;
        shorter_p = s;
        bigger_end = t + t_length;
        shorter_end = s + s_length;
    }
    bool oneChance = true;
    while (bigger_p != bigger_end && (*bigger_p == *shorter_p || oneChance)) {
        if (*bigger_p != *shorter_p) {
            oneChance = false;
            bigger_p ++;
        } else {
            bigger_p ++;
            shorter_p ++;
        }
    }
    return bigger_p == bigger_end && !oneChance;
    
}