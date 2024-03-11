int cmp(void * a, void * b) {
    if (*(int *)a < *(int *)b) {
        return 1;
    }
    return -1;
}
int minimumBoxes(int* apple, int appleSize, int* capacity, int capacitySize) {
    int appleSum = 0;
    for (int i = 0; i < appleSize; ++i) {
        appleSum += apple[i];
    }
    qsort(capacity, capacitySize, sizeof(int), cmp);
    int num = 0;
    for (int i = 0; i < capacitySize; ++i) {
        appleSum -= capacity[i];
        num ++;
        if (appleSum <= 0)
            return num;
    }
    return 0;
}