class Solution {
public:
    int getSum(int a, int b) {
        int r, C = 0;
        int result = 0;
        size_t s = sizeof(int);
        for (size_t i = 0; i != s; ++i) {
            unsigned int t = 0x01 << i;
            unsigned int v1 = a && t;
            unsigned int v2 = b && t;
            r = (v1 ^ v2) ^ C;
            C = (v1 & v2) | (v1 & C) | (v2 & C);
            C <<= 1;
            result |= r; 
        }
        return result;
    }
};