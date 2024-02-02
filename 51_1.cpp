class Solution {

private:
    unsigned int row = 0;
    unsigned int col = 0;
    unsigned int right_down = 0;
    unsigned int left_down = 0;
    vector<string> current = {};


    int get_index_rd(int i, int j, int n) {
        return (i - j + n - 1);
    }
    int get_index_ld(int i, int j) {
        return (i + j);
    }

    void dfs(int i, int j, int m, vector<vector<string>>& ret_ans) {
        int n = current.size();
        int next_i = i + (j + 1) / n;
        int next_j = (j + 1) % n;

        if (m == 0) { 
            ret_ans.push_back(vector<string>(current.begin(), current.end()));
            return ;
        }
        if (i == n && j == 0) { return ; }

        dfs(next_i, next_j, m, ret_ans);

        int index_rd = get_index_rd(i, j, n), index_ld = get_index_ld(i, j);
        bool is_occupied = (row & (0x1 << i)) || (col & (0x1 << j))
                                        ||  (right_down & (0x1 << index_rd)) || (left_down & (0x1 << index_ld));
        if (is_occupied) { return ; }

        row |= 0x1 << i; col |= 0x1 << j;
        right_down |= 0x1 << index_rd; left_down |= 0x1 << index_ld;
        current[i][j] = 'Q';
        dfs(next_i, next_j, m - 1, ret_ans);

        current[i][j] = '.';
        row ^= 0x1 << i; col ^= 0x1 << j;
        right_down ^= 0x1 << index_rd; left_down ^= 0x1 << index_ld;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret_ans = {};
        string init_str = "";
        for (int i = 0; i < n; ++i) {
            init_str += '.';
        }
        for (int i = 0; i < n; ++i) {
            current.push_back(init_str);
        }
        dfs(0, 0, n, ret_ans);
        return ret_ans;
    }
};