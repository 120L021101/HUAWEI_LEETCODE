class Solution {
public:
    int myAtoi(string s) {
        int start = 0;
        // 空格
        while (start < s.length() && (s[start] == ' '))
            start ++;
        if (s[start] == '+' || s[start] == '-')
            start ++;

        if (start == s.length() || s[start] < '0' || s[start] > '9')
            return 0;

        // 是否正数
        bool is_positive = (0 == start) || (s[start - 1] != '-');
        // 前导0
        while (start < s.length() && s[start] == '0')
            start ++;
        // 找尾巴
        int end = start;
        while (end < s.length() && (s[end] >= '0' && s[end] <= '9'))
            end ++;
        int limit = is_positive ? (0x80000001) : (0x80000000);
        int pointer = start;
        int ret_val = 0;
        while (pointer < end) {
            int this_val = - (s[pointer] - '0');
            if (ret_val < (limit - this_val) / 10) {
                return is_positive ? -limit : limit;
            }
            ret_val = ret_val * 10 + this_val;
            pointer ++;
        }
        return is_positive ? -ret_val : ret_val;
    }
};