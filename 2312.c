typedef struct _Hash_node {
    long long key;
    int val;
    UT_hash_handle hh;
} Hash_node;

typedef Hash_node * Hash_table;

#define hash(a, b) (((long long)a << 32) ^ b)
#define F(x, y) (x * (n + 1) + y)
long long memorySearch(int i, int j, int m, int n, long long * memory, Hash_table hash_table) {
    if (memory[F(i, j)] != -1) return memory[F(i, j)];
    long long key = hash(i, j), ret_val = 0;
    Hash_node * find_node;
    HASH_FIND(hh, hash_table, &key, sizeof(long long), find_node);
    if (find_node) { ret_val = find_node->val; }
    if (i > 1) {
        for (int split_i = 1; split_i < i; ++split_i) {
            long long val1 = memorySearch(split_i, j, m, n, memory, hash_table);
            long long val2 = memorySearch(i - split_i, j, m, n, memory, hash_table);
            ret_val = fmax(ret_val, val1 + val2);
        }        
    }
    if (j > 1) {
        for (int split_j = 1; split_j < j; ++split_j) {
            long long val1 = memorySearch(i, split_j, m, n, memory, hash_table);
            long long val2 = memorySearch(i, j - split_j, m, n, memory, hash_table);
            ret_val = fmax(ret_val, val1 + val2);
        }   
    }
    return memory[F(i, j)] = ret_val;
}

long long sellingWood(int m, int n, int** prices, int pricesSize, int* pricesColSize) {
    Hash_table hash_table = NULL;  
    for (int i = 0; i < pricesSize; ++i) {
        Hash_node * add_node = (Hash_node *)malloc(sizeof(Hash_node));
        add_node->key = hash(prices[i][0], prices[i][1]);
        add_node->val = prices[i][2];
        HASH_ADD_KEYPTR(hh, hash_table, &add_node->key, sizeof(long long), add_node);
    }
    long long memory[m + 1][n + 1];
    memset(memory, 0xFF, sizeof(long long) * (m + 1) * (n + 1));
    long long maxVal = 0;
    memorySearch(m, n, m, n, memory, hash_table);
    return memory[m][n];
}