int minimumTimeToInitialState(char* word, int k) {
    int word_length = strlen(word);
    unsigned int next[word_length];
    next[0] = 0;
    int i = 1, j = 0;
    while (i < word_length) {
        while (j && word[i] != word[j])
            j = next[j - 1];
        if (word[i] == word[j])
            j ++;
        next[i++] = j;
    }
    j = 0;
    i = k;
    while(i < word_length) {
        while (j && word[i] != word[j])
            j = next[j - 1];
        if (word[i] == word[j]){
            j ++;
            i ++;
        }
        else
            i = (i / k + 1) * k;
    }
    while (j && (word_length - j) % k)
        j = next[j - 1];
    return (word_length - j + k - 1) / k;
}