int dfs(int x, int y, int * memory) {
    if (x <= y) {
        return y - x;
    }
    
    if (memory[x]) return memory[x];
    
    int op1 = x - y;
    int op2 = dfs(x / 5, y, memory) + (x % 5) + 1;
    int op3 = dfs(x / 5 + 1, y, memory) + 5 - (x % 5) + 1;
    int op4 = dfs(x / 11, y, memory) + (x % 11) + 1;
    int op5 = dfs(x / 11 + 1, y, memory) + 11 - (x % 11) + 1;
    op2 = fmin(op2, op3);
    op4 = fmin(op4, op5);
    op2 = fmin(op2, op4);
    op1 = fmin(op1, op2);
    return memory[x] = op1;
}

int minimumOperationsToMakeEqual(int x, int y) {
    if (x <= y) {
        return y - x;
    }
    int memory[ 20000 ] = { 0 };
    return dfs(x, y, memory);
}