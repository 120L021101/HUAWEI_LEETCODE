class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> stack {-1};
        int max_length = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                stack.push_back(i);
                continue;
            }
            stack.pop_back();
            if (stack.size() == 0) {
                stack.push_back(i);
                continue;
            }
            int edge = stack[stack.size() - 1];
            max_length = max(max_length, (i - edge));
        }
        return max_length;
    }
};