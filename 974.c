typedef struct _Hash_node {
    int key;
    int val;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node * Hash_table;

int subarraysDivByK(int* nums, int numsSize, int k) {
    Hash_table hash_table = NULL;
    Hash_node * hash_node = (Hash_node *)malloc(sizeof(Hash_node));
    hash_node->key = 0;
    hash_node->val = 1;
    HASH_ADD_KEYPTR(hh, hash_table, &hash_node->key, sizeof(int), hash_node);
    int count = 0;
    int preFix = 0;
    for (int i = 0; i < numsSize; ++i) {
        preFix += nums[i];
        int key = preFix % k;
        if (key < 0) key += k;
        hash_node = NULL;
        HASH_FIND(hh, hash_table, &key, sizeof(int), hash_node);
        if (hash_node != NULL) {
            count += hash_node->val;
            hash_node->val += 1;
        } else {
            hash_node = (Hash_node *)malloc(sizeof(Hash_node));
            hash_node->key = key;
            hash_node->val = 1;
            HASH_ADD_KEYPTR(hh, hash_table, &hash_node->key, sizeof(int), hash_node);
        }
    }
    return count;
}