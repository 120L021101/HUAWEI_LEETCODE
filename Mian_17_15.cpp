class Solution {
private:
    bool judge(unordered_set<string>& all_words, string& judge_str, int start) {
        decltype(judge_str.length()) str_len = judge_str.length();
        if (start == str_len) { return true; }
        string next_str = "";
        int p = start;
        int end = start == 0 ? str_len - 1 : str_len;
        while (p != end) {
            next_str += judge_str[p++];
            if (!all_words.count(next_str))
                continue;
            if (judge(all_words, judge_str, p)) {
                return true;
            }
        }
        return false;
    }
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string &b) {
            decltype(a.length()) a_length = a.length(), b_length = b.length();
            if (a_length != b_length) {
                return a_length > b_length;
            }
            return a < b;
        });
        unordered_set<string> all_words (words.begin(), words.end());
        for (string& word : words) {
            if (judge(all_words, word, 0))
                return word;
        }
        return "";
    }
};