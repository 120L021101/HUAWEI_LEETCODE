int minimumTimeToInitialState(char* word, int k) {
    int word_length = strlen(word);
    unsigned char next[word_length];
    next[0] = 0;
    int j = 0;
    for (int i = 1; i != word_length; ++i) {
        while (j && word[i] != word[j])
            j = next[j - 1];
        if (word[i] == word[j])
            j ++;
        next[i] = j;
    }
    j = 0;
    for (int i = 1; i < word_length; ++i) {
        while (j && word[i] != word[j])
            j = next[j - 1];
        if (word[i] == word[j])
            j ++;
    }
    while (j && (word_length - j) % k)
        j = next[j - 1];
    return (word_length - j + k - 1) / k;
}