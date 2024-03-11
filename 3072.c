/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _BIT
{
    int * tree;
    int length;
} BIT;

void update(BIT * bitree, int hashed_index) {
    while (hashed_index <= bitree->length) {
        bitree->tree[hashed_index - 1] ++;
        hashed_index += hashed_index & -hashed_index;
    }
}
int smallerCount(BIT * bitree, int hashed_index) {
    int count = 0;
    while (hashed_index) {
        count += bitree->tree[hashed_index - 1];
        hashed_index -= hashed_index & -hashed_index;
    }
    return count;
}


typedef struct _Hash_node
{
    int key;
    int idx;
    UT_hash_handle hh;
} Hash_node;
typedef Hash_node * Hash_table;

static int cmp(void * a, void * b) {
    if (*(int *)a < *(int *)b)
        return -1;
    return 1;
}

static Hash_table find_hash(int* nums, int numsSize) {
    int r_nums[numsSize];
    memcpy(r_nums, nums, sizeof(int) * numsSize);
    qsort(r_nums, numsSize, sizeof(int), cmp);
    Hash_table hash_table = NULL;
    int idx = 1;
    for (int i = 0; i < numsSize; ++i) {
        int num = r_nums[i];
        Hash_node * find_node = NULL;
        HASH_FIND(hh, hash_table, &num, sizeof(int), find_node);
        if (!find_node) {
            Hash_node * find_node = (Hash_node *)malloc(sizeof(Hash_node));
            find_node->key = num;
            find_node->idx = idx ++;
            HASH_ADD_KEYPTR(hh, hash_table, &find_node->key, sizeof(int), find_node);
        }
    }
    return hash_table;
}



int* resultArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    Hash_table idx_hash = find_hash(nums, numsSize);
    int biggestIdx = HASH_COUNT(idx_hash);

    BIT bitree1, bitree2;
    bitree1.tree = (int *)calloc(biggestIdx, sizeof(int));
    bitree1.length = biggestIdx;
    bitree2.tree = (int *)calloc(biggestIdx, sizeof(int));
    bitree2.length = biggestIdx;

    int arr1[numsSize], length1 = 1;
    int arr2[numsSize], length2 = 1;
    arr1[0] = nums[0];
    Hash_node * find_node = NULL;
    HASH_FIND(hh, idx_hash, nums, sizeof(int), find_node);
    update(&bitree1, find_node->idx);
    arr2[0] = nums[1];
    HASH_FIND(hh, idx_hash, nums + 1, sizeof(int), find_node);
    update(&bitree2, find_node->idx);
    for (int i = 2; i < numsSize; ++i) {
        HASH_FIND(hh, idx_hash, nums + i, sizeof(int), find_node);
        int greaterCount1 = length1 - smallerCount(&bitree1, find_node->idx);
        
        HASH_FIND(hh, idx_hash, nums + i, sizeof(int), find_node);
        int greaterCount2 = length2 - smallerCount(&bitree2, find_node->idx);

        if (greaterCount1 > greaterCount2) {
            arr1[length1 ++] = nums[i];
            update(&bitree1, find_node->idx);
        }
        else if (greaterCount1 < greaterCount2) {
            arr2[length2 ++] = nums[i];
            update(&bitree2, find_node->idx);
        }
        else if (length1 < length2) {
            arr1[length1 ++] = nums[i];
            update(&bitree1, find_node->idx);
        }
        else if (length2 < length1) {
            arr2[length2 ++] = nums[i];
            update(&bitree2, find_node->idx);
        }
        else {
            arr1[length1 ++] = nums[i];
            update(&bitree1, find_node->idx);
        }
    }
    memcpy(nums, arr1, sizeof(int) * length1);
    memcpy(nums + length1, arr2, sizeof(int) * length2);
    return nums;
}