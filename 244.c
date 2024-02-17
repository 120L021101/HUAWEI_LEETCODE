
typedef struct _Link_pos {
    int pos;
    struct _Link_pos * next;
}Link_pos;

typedef struct _Hash_node {
    char * key;
    unsigned int length;
    Link_pos * header;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node* Hash_table;

typedef struct {
    Hash_table hash_table;
} WordDistance;

static void addPos(Link_pos * header, int pos) {
    Link_pos * newNode = (Link_pos *)malloc(sizeof(Link_pos));
    newNode->pos = pos;
    newNode->next = header->next;
    header->next = newNode;
}

WordDistance* wordDistanceCreate(char** wordsDict, int wordsDictSize) {
    WordDistance * wordDistance = (WordDistance *)malloc(sizeof(WordDistance));
    wordDistance->hash_table = NULL;

    int pos = 0;
    for (char ** wordAddr = wordsDict, ** wordEnd = wordsDict + wordsDictSize;
            wordAddr != wordEnd; wordAddr ++, pos ++) {
        char * word = *wordAddr;
        int wordLength = strlen(word);
        Hash_node * hash_node = NULL;
        HASH_FIND(hh, wordDistance->hash_table, word, sizeof(char) * wordLength, hash_node);
        if (hash_node) {
            addPos(hash_node->header, pos);
            continue;
        }
        hash_node = (Hash_node *)malloc(sizeof(Hash_node));
        hash_node->header = (Link_pos *)malloc(sizeof(Link_pos));
        hash_node->header->next = NULL;
        hash_node->key = word;
        addPos(hash_node->header, pos);
        HASH_ADD_KEYPTR(hh, wordDistance->hash_table, word, sizeof(char) * wordLength, hash_node);
    }
    return wordDistance;
}

int wordDistanceShortest(WordDistance* obj, char* word1, char* word2) {
    int length1 = strlen(word1), length2 = strlen(word2);
    Link_pos * pos1, * pos2;

    Hash_node * hash_node1 = NULL, * hash_node2 = NULL;
    HASH_FIND(hh, obj->hash_table, word1, sizeof(char) * length1, hash_node1);
    HASH_FIND(hh, obj->hash_table, word2, sizeof(char) * length2, hash_node2);
    
    pos1 = hash_node1->header->next;
    pos2 = hash_node2->header->next;
    
    unsigned int minDistance = -1;
    while (1) {
        int wpos1 = pos1->pos;
        int wpos2 = pos2->pos;
        minDistance = fmin(minDistance, abs(wpos1 - wpos2));
        if (!pos1->next && !pos2->next)
            break;
        if (!pos1->next) {
            pos2 = pos2->next;
            continue;
        }
        if (!pos2->next) {
            pos1 = pos1->next;
            continue;
        }
        if (pos1->next->pos < pos2->next->pos) {
            pos2 = pos2->next;
            continue;
        }
        pos1 = pos1->next;
    }

    return minDistance;
}

static void freeLink(Link_pos * header) {
    Link_pos * before = header, * after = header->next;
    while (after) {
        free(before);
        before = after;
        after = after->next;
    }
    free(before);
}

void wordDistanceFree(WordDistance* obj) {
    Hash_table hash_table = obj->hash_table;
    for (Hash_node * hash_node = hash_table; hash_node; ) {
        freeLink(hash_node->header);
        Hash_node * next_node = hash_node->hh.next;
        free(hash_node);
        hash_node = next_node;
    }   
}

/**
 * Your WordDistance struct will be instantiated and called as such:
 * WordDistance* obj = wordDistanceCreate(wordsDict, wordsDictSize);
 * int param_1 = wordDistanceShortest(obj, word1, word2);
 
 * wordDistanceFree(obj);
*/