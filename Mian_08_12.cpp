class Solution {

private:
    unsigned int col_av;
    unsigned int lr_av;
    unsigned int rl_av;

private:
    int view(int val) {
        int digit = 0;
        while (val >>= 1) {
            digit ++;
        }
        return digit;
    }
    void search(vector<vector<string>>& result, int n, int row, vector<string>& current) {
        if (row == n) {
            result.emplace_back(vector<string>(current.begin(), current.end()));
            return;
        }
        unsigned int avaliable = col_av & (rl_av >> row) & (lr_av >> (n - 1 - row));
        while (avaliable) {
            unsigned int triance = avaliable & (-avaliable);
            avaliable ^= triance;
            col_av ^= triance;
            rl_av ^= triance << row;
            int pick_col = view(triance);
            lr_av ^= triance << (n - 1 - row);
            string temp ( n, '.' );
            temp[pick_col] = 'Q';
            current.push_back(move(temp));
            search(result, n, row + 1, current);
            current.pop_back();
            col_av |= triance;
            rl_av |= triance << row;
            lr_av |= triance << (n - 1 - row);
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        col_av = (0x1 << n) - 1;
        lr_av = rl_av = (0x1 << (2 * n - 1)) - 1;
        vector<vector<string>> result;
        vector<string> current;
        search(result, n, 0, current);
        return result;
    }
};