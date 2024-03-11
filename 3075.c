int cmp(void * a, void * b) {
    return *(int *)b - *(int *)a;
}
long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), cmp);
    long long expectHappiness = 0;
    for (int i = 0; i < k; ++i) {
        expectHappiness += fmax(0, happiness[i] - i);
    }
    return expectHappiness;
}