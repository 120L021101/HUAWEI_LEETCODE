typedef struct _Hash_node {
    long long key;
    int val;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node * Hash_table;

static int cmp(void * a, void * b) {
    long long val1 = *(long long *)a;
    long long val2 = *(long long *)b;
    if (val1 < val2) return -1;
    return 1; 
}

static Hash_table discrete(int* nums, int numsSize, long long * maxVal) {
    long long* rec_nums = (long long *)malloc(sizeof(long long) * (2 * numsSize));
    *maxVal = nums[0];
    for (int i = 0; i < numsSize; ++i) {
        rec_nums[2 * i] = nums[i];
        rec_nums[2 * i + 1] = 2 * (long long)nums[i];
        *maxVal = fmax(*maxVal, fmax(rec_nums[2 * i], rec_nums[2 * i + 1]));
    }
    qsort(rec_nums, 2 * numsSize, sizeof(long long), cmp);
    Hash_table hash_table = NULL;
    int order = 1;
    for (int i = 0; i < 2 * numsSize; ++i) {
        Hash_node * find_node = NULL;
        HASH_FIND(hh, hash_table, &rec_nums[i], sizeof(long long), find_node);
        if (!find_node) {
            find_node = (Hash_node *)malloc(sizeof(Hash_node));
            find_node->key = rec_nums[i];
            find_node->val = order ++;
            HASH_ADD_KEYPTR(hh, hash_table, &find_node->key, sizeof(long long), find_node);
        }
    }
    free(rec_nums);
    return hash_table;
}

typedef struct _BIT {
    int * tree;
    int n;
} BIT;
void addDepth(BIT * bitree, long long num, Hash_table numMap) {
    Hash_node * mapIdx = NULL;
    HASH_FIND(hh, numMap, &num, sizeof(long long), mapIdx);
    int idx = mapIdx->val;
    while (idx <= bitree->n) {
        bitree->tree[idx - 1] ++;
        idx += idx & -idx;
    }
}
int count(BIT * bitree, long long rightEnd, Hash_table numMap) {
    Hash_node * mapIdx = NULL;
    HASH_FIND(hh, numMap, &rightEnd, sizeof(long long), mapIdx);
    int idx = mapIdx->val;
    int retCount = 0;
    while (idx) {
        retCount += bitree->tree[idx - 1];
        idx -= idx & -idx;
    }
    return retCount;
}

int reversePairs(int* nums, int numsSize) {
    
    long long maxVal = 0;
    Hash_table numMap = discrete(nums, numsSize, &maxVal);   
    BIT bitree;
    bitree.n = HASH_COUNT(numMap);
    bitree.tree = (int *)calloc(bitree.n, sizeof(int));

    int retCount = 0;
    for (int i = 0; i < numsSize; ++i) {
        long long left = (long long)nums[i] * 2;
        int leftCount = count(&bitree, left, numMap);
        int rightCount = count(&bitree, maxVal, numMap);
        retCount += rightCount - leftCount;
        addDepth(&bitree, nums[i], numMap);
    }
    return retCount;
}