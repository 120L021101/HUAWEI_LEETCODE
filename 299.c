typedef struct _Hash_node
{
    int key;
    int count;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node * Hash_table;


char* getHint(char* secret, char* guess) {
    int length = strlen(secret);
    int Bull = 0;
    char sC[length + 1], gC[length + 1];
    int length2 = 0;
    for (int i = 0; i < length; ++i) {
        if (secret[i] == guess[i]) {
            Bull ++;
        } else {
            sC[length2] = secret[i];
            gC[length2 ++] = guess[i];
        }
    }
    sC[length2] = '\0';
    gC[length2] = '\0';
    Hash_table hash_table = NULL;
    for (int i = 0; i < length2; ++i) {
        char n = sC[i] - '0';
        Hash_node * find_node = NULL;
        HASH_FIND(hh, hash_table, &n, sizeof(char), find_node);
        if (!find_node) {
            find_node = (Hash_node *)malloc(sizeof(Hash_node));
            find_node->count = 1;
            find_node->key = n;
            HASH_ADD_KEYPTR(hh, hash_table, &find_node->key, sizeof(char), find_node);
        } else {
            find_node->count ++;
        }
    }
    int Cow = 0;
    for (int i = 0; i < length2; ++i) {
        char n = gC[i] - '0';
        Hash_node * find_node = NULL;
        HASH_FIND(hh, hash_table, &n, sizeof(char), find_node);
        if (find_node && find_node->count) {
            Cow ++;
            find_node->count --;
        }
    }
    char * buf = (char *)malloc(10000);
    sprintf(buf, "%dA%dB", Bull, Cow);
    return buf;
}