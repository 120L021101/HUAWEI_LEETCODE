class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0;
        unordered_set<char> current;
        int max_length = 0;
        while (end < s.length()) {
            char current_char = s[end];
            while (current.count(current_char)) {
                current.erase(s[start++]);
            }
            current.insert(current_char);
            end ++;
            if (end - start > max_length) {
                max_length = end - start;
            }
        }
        return max_length;
    }
};