class Solution {
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        vector<vector<int>> ret;
        for (string& small : smalls) {
            if (small.length() == 0) {
                ret.push_back({});
                continue;
            }
            int next[small.length()];
            next[0] = 0;
            int i = 1, j = 0;
            while (i < small.length()) {
                while (j && small[i] != small[j]) {
                    j = next[j - 1];
                }
                if (small[i] == small[j]) {
                    j ++;
                }
                next[i ++] = j;
            }
            vector<int> search;
            i = 0, j = 0;
            while (i < big.length() && j < small.length()) {
                while (j && big[i] != small[j]) {
                    j = next[j - 1];
                }
                if (big[i] == small[j]) j ++;
                i ++;
                if (j == small.length()) {
                    search.push_back(i - small.length());
                    j = next[j - 1];
                }

            }
            ret.push_back(move(search));
        }
        return ret;
    }
};