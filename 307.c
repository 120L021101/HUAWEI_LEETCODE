


typedef struct {
    int * tree;
    int length;
    int * nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray* numArray = (NumArray *)malloc(sizeof(NumArray));
    numArray->tree = (int *)calloc(numsSize, sizeof(int));
    numArray->length = numsSize;
    numArray->nums = nums;

    for (int i = 1; i <= numsSize; ++i) {
        int ic = i;
        while (ic <= numsSize) {
            numArray->tree[ic - 1] += nums[i - 1];
            ic += ic & -ic;
        }
    }
    return numArray;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    int diff = val - obj->nums[index];
    obj->nums[index] = val;
    index ++;
    while (index <= obj->length) {
        obj->tree[index - 1] += diff;
        index += index & -index;
    }
}

static int calculateVal(const NumArray* obj, int end) {
    int sumVal = 0;
    end ++;
    while (end) {
        int pickEnd = end & -end;
        sumVal += obj->tree[end - 1];
        end -= pickEnd;
    }
    return sumVal;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    if (left)
        return calculateVal(obj, right) - calculateVal(obj, left - 1);
    return calculateVal(obj, right);
}

void numArrayFree(NumArray* obj) {
    free(obj->tree);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/