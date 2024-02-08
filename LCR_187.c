int iceBreakingGame(int num, int target) {
    int f = 0;
    for (int i = 1; i < num; ++i) {
        f = (f + target) % (i + 1);
    }
    return f;
}