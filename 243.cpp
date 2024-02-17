class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int last_word1 = -1, last_word2 = -1;
        unsigned int min_distance = -1;
        for (int i = 0; i < wordsDict.size(); ++i) {
            string& word = wordsDict[i];
            if (word == word1) {
                last_word1 = i;
            }
            if (word == word2) {
                last_word2 = i;
            }
            if (last_word1 == -1 || last_word2 == -1)
                continue;
            min_distance = min(min_distance, abs(last_word1 - last_word2));
        }
        return min_distance;
    }
};