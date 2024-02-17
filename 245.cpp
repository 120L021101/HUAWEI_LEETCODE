class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> index_map;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (!index_map.count(wordsDict[i]))
                index_map[wordsDict[i]] = {};
            index_map[wordsDict[i]].push_back(i);
        }
        int p1 = 0, p2 = 0;
        unsigned int minDistance = -1;
        vector<int>& index1 = index_map[word1];
        vector<int>& index2 = index_map[word2];
        if (word1 == word2) {
            p2 = 1;
            while (p2 != index1.size()) {
                minDistance = fmin(minDistance, abs(index1[p1] - index1[p2]));
                p1 ++;
                p2 ++;
            }
            return minDistance;
        }
        while (true) {
            minDistance = fmin(minDistance, abs(index1[p1] - index2[p2]));
            if (p1 + 1 == index1.size() && p2 + 1 == index2.size())
                break;
            if (p1 + 1 == index1.size()) {
                p2 ++;
                continue;;
            }
            if (p2 + 1 == index2.size()) {
                p1 ++;
                continue;
            }
            if (index1[p1 + 1] < index2[p2 + 1]) {
                p1 ++;
            }
            else {
                p2 ++;
            }
        }
        return minDistance;
    }
};