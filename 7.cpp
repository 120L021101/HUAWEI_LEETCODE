class Solution {
public:
    int reverse(int x) {
        if (x == 0x80000000) return 0;
        bool flag = x > 0;
        x = abs(x);
        int trans_x = 0;
        int max_limit = 0x7FFFFFFF;
        cout << max_limit << endl;
        while (x) {
            int val = x % 10;
            x /= 10;
            if (trans_x > (max_limit - val) / 10) return 0;
            trans_x = trans_x * 10 + val;
        }
        return flag ? trans_x : -trans_x;
    }
};