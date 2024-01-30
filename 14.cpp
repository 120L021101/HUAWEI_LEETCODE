class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pointer = 0;
        char ch = 0; 
        bool found = false;
        while (1) {
            for (string& str : strs) {
                if (pointer == str.length()) {
                    return str.substr(0, pointer);
                }
                if (!found) {
                    ch = str[pointer];
                    found = true;
                } else {
                    if (ch != str[pointer]) {
                        return str.substr(0, pointer);
                    }
                }
            }
            pointer ++; found = false;
        }
        return "";
    }
};