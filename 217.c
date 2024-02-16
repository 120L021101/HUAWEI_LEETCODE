typedef struct _Hash_node {
    int key;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node* Hash_table;

bool containsDuplicate(int* nums, int numsSize) {

    Hash_table hash_table = NULL;
    for (int * pointer = nums, * end = nums + numsSize; pointer != end; ++pointer) {
        int num = *pointer;
        Hash_node* hash_node = NULL;
        HASH_FIND_INT(hash_table, &num, hash_node);
        if (hash_node) {
            return true;
        }
        hash_node = (Hash_node *)malloc(sizeof(Hash_node));
        hash_node->key = num;
        HASH_ADD_INT(hash_table, key, hash_node);
    }
    return false;
}