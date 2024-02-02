class Solution {

private:
    unsigned int row = 0;
    unsigned int diagnose_rd = 0;
    unsigned int diagnose_ld = 0;

    vector<string> current = {};

    int view(int num) {
        int digit = -1;
        while (num) {
            num >>= 1;
            digit ++;
        }
        return digit;
    }

    void dfs(int r, vector<vector<string>>& ret_ans) {
        int n = current.size();
        if (r == n) {
            ret_ans.push_back(vector<string>(current.begin(), current.end()));
            return;
        }
        unsigned int diagnose_rd_cur = diagnose_rd >> (n - 1 - r);
        unsigned int diagnose_ld_cur = diagnose_ld >> r;
        unsigned int forbidden_flag = (0x00000001 << n) - 1;
        unsigned int forbidden = (row | diagnose_rd_cur | diagnose_ld_cur) & forbidden_flag;
        while (forbidden != forbidden_flag) {
            int allowance = (~forbidden) & forbidden_flag;
            unsigned int triance = allowance & (-allowance);
            row |= triance;
            diagnose_rd |= triance << (n - 1 - r);
            diagnose_ld |= triance << r;
            current[r][view(triance)] = 'Q';
            dfs(r + 1, ret_ans);
            row ^= triance;
            current[r][view(triance)] = '.';
            diagnose_rd ^= triance << (n - 1 - r);
            diagnose_ld ^= triance << r;
            forbidden |= triance;
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret_ans;
        string init_str = "";
        for (int i = 0; i < n; ++i) {
            init_str += '.';
        }
        for (int i = 0; i < n; ++i) {
            current.push_back(init_str);
        }
        dfs(0, ret_ans);
        return ret_ans;
    }
};