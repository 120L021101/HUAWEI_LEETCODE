class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long current_C = 0;
        vector<int> div_results;
        for (int i = 0; i < word.length(); ++i) {
            int cur_n = word[i] - '0';
            current_C = (current_C * 10 + cur_n) % m;
            div_results.push_back(!current_C);
        }
        return div_results;
    }
};