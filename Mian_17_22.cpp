class Solution {

private:
    bool isTransable(const string& word1, const string& word2) {
        if (word1.length() != word2.length()) return false;
        int diff = 0;
        for (int i = 0; i < word1.length() and diff <= 1; ++i) {
            diff += (word1[i] != word2[i]);
        }
        return diff == 1;
    }

public:
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<string> search {beginWord};
        vector<unsigned char> visited (wordList.size(), 0);
        while (search.size()) {
            string& word = search[search.size() - 1];
            if (word == endWord) break;
            bool find = false;
            for (int i = 0; i < wordList.size() and !find; ++i) {
                if (visited[i]) continue;
                if (isTransable(word, wordList[i])) {
                    search.push_back(wordList[i]);
                    visited[i] = 1;
                    find = true;
                }
            }
            if (!find) {
                search.pop_back();
                continue;
            }
        }
        return search;
    }
};