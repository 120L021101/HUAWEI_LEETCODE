class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int base = 10;
        int add_num = 9, factor = 9;
        for (int i = 1; i != n; ++i) {
            base += add_num *= (factor --);
        }
        return base;
    }
};