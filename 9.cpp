class Solution {
public:
    bool isPalindrome(int x) {
        int digit = 1;
        int temp_x = x / 10;
        while (temp_x) {
            digit *= 10;
            temp_x /= 10;
        }
        temp_x = x;
        while (temp_x) {
            if (temp_x % 10 != x / digit) return false;
            temp_x /= 10;
            x %= digit;
            digit /= 10;
        }
        return true;
    }
};