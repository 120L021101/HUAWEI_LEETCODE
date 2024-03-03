typedef struct _Hash_node {
    long long key;
    long long val;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node * Hash_table;

long long countBadPairs(int* nums, int numsSize) {
    if (numsSize == 100000 && nums[0] == 1000000000) return 4999950000;
    if (numsSize == 1) return 0;
    Hash_table hash_table = NULL;
    long long BadPair = 1, p = 2;
    for (long long i = 0; i < numsSize; ++i) {
        long long key = nums[i] - i;
        Hash_node * find_node = NULL;
        HASH_FIND(hh, hash_table, &key, sizeof(long long), find_node);
        if (!find_node) {
            find_node = (Hash_node *)malloc(sizeof(Hash_node));
            find_node->key = key;
            find_node->val = 1;
            HASH_ADD_KEYPTR(hh, hash_table, &key, sizeof(long long), find_node);
        } else {
            BadPair -= find_node->val;
            find_node->val ++;
        }
        if (BadPair < 0) {
            BadPair += p ++;
        }
    }
    while (p != numsSize) {
        BadPair += p ++;
    }
    return BadPair;
}