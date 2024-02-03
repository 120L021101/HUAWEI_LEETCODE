class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> find_pair = {
            {')' , '('}, {'}' , '{'}, {']' , '['}
        };
        vector<char> char_stack;
        for (char ch : s) {
            // 判断左右
            if (find_pair.find(ch) == find_pair.end()) {
                char_stack.push_back(ch);
            }
            else {
                if (char_stack.size() == 0) {
                    return false;
                }
                char final_char = char_stack[char_stack.size() - 1];
                if (final_char == find_pair[ch]) {
                    char_stack.pop_back();
                }
                else {
                    return false;
                }
            }
        }
        return char_stack.size() == 0;
    }
};