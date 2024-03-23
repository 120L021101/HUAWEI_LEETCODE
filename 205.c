typedef struct _Hash_node
{
    char key;
    char val;
    UT_hash_handle hh;
} Hash_node;

typedef Hash_node * Hash_table;

bool isIsomorphic(char* s, char* t) {
    Hash_table hash1 = NULL;
    int strlength = strlen(s);
    for (int i = 0; i < strlength; ++i) {
        Hash_node * hash_node = NULL;
        HASH_FIND(hh, hash1, s + i, sizeof(char), hash_node);
        if (hash_node != NULL) {
            if (hash_node->val != t[i])
                return false;
        }
        else {
            hash_node = (Hash_node *)malloc(sizeof(Hash_node));
            hash_node->key = s[i];
            hash_node->val = t[i];
            HASH_ADD_KEYPTR(hh, hash1, &hash_node->key, sizeof(char), hash_node);
        }
    }

    hash1 = NULL;
    for (int i = 0; i < strlength; ++i) {
        Hash_node * hash_node = NULL;
        HASH_FIND(hh, hash1, t + i, sizeof(char), hash_node);
        if (hash_node != NULL) {
            if (hash_node->val != s[i])
                return false;
        }
        else {
            hash_node = (Hash_node *)malloc(sizeof(Hash_node));
            hash_node->key = t[i];
            hash_node->val = s[i];
            HASH_ADD_KEYPTR(hh, hash1, &hash_node->key, sizeof(char), hash_node);
        }
    }
    return true;
}