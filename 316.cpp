class Solution {
public:
    string removeDuplicateLetters(string s) {
        int count[26] = { 0 };
        for (char c : s) {
            count[c - 'a'] ++;
        }
        vector<char> up_stack;
        int stack_size = 0;
        char top_c;
        char visited[26] = { 0 };
        for (char c : s) {
            count[c - 'a'] --;
            if (visited[c - 'a']) { continue; }
            while (stack_size) {
                top_c = up_stack[stack_size - 1];
                if (top_c > c && count[top_c - 'a']) {
                    up_stack.pop_back();
                    stack_size --;
                    visited[top_c - 'a'] = 0;
                }
                else break;
            }
            up_stack.push_back(c);
            stack_size ++;
            visited[c - 'a'] = 1;
        }
        return string(up_stack.begin(), up_stack.end());
    }
};