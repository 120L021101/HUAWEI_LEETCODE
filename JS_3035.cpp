class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int count[26] = { 0 };
        vector<int> lengths;
        for (string& word : words) {
            for (char c : word) {
                count[c - 'a'] ++;
            }
            lengths.push_back(word.length());
        }
        int odd = 0, even = 0;
        for (int i = 0; i < 26; ++i) {
            even += count[i] / 2;
            odd += count[i] % 2;
        }
        sort(lengths.begin(), lengths.end(), [](int &a, int &b) {return a < b;});
        int available = 0;
        for (int& length : lengths) {
            even -= length / 2;
            odd -= length % 2;
            if (odd == -1) {
                even -= 1;
                odd = 1;
            }
            if (even < 0) break;
            available ++;
        }
        return available;
    }
};