char* capitalizeTitle(char* title) {
    char * pointer = title;
    while (1) {
        char * pStart = pointer;
        for (int i = 0; *pointer && *pointer != ' '; ++i, ++pointer) {
            char ch = *pointer;
            if (ch >= 'A' && ch <= 'Z') {
                *pointer = ch - 'A' + 'a';
            }
            if (i == 2)
                *pStart = *pStart - 'a' + 'A';
        }
        if (!*pointer) break;
        pointer ++;
    }
    return title;
}