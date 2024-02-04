class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> ch_count;
        for (char ch : s) {
            if (!ch_count.count(ch)) {
                ch_count[ch] = 0;
            }
            ch_count[ch]++;
        }
        int od_num = 0;
        for (auto item : ch_count) {
            if (item.second % 2 == 1) {
                od_num ++;
            }
            if (od_num > 1)
                return false;
        }
        return true;
    }
};