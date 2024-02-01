class Solution {

private:
    unsigned int rows[9];
    unsigned int cols[9];
    unsigned int block[3][3];

    int view(unsigned int val) {
        int digit = 0;
        while (val) {
            val >>= 1;
            digit ++;
        }
        return digit;
    }

    bool dfs(int i, int j, vector<vector<char>>& board) {
        if (i == 9 && j == 0) {
            return true;
        }

        int next_i = i + (j + 1) / 9;
        int next_j = (j + 1) %  9;

        if (board[i][j] != '.') {
            return dfs(next_i, next_j, board);
        }
        unsigned int forbidden = rows[i] | cols[j] | block[i / 3][j / 3];
        while (forbidden != (unsigned int) 0x1FF) {
            unsigned int allowance = (~forbidden) & 0x1FF;
            unsigned int triance = allowance & (-allowance);
            rows[i] |= triance;
            cols[j] |= triance;
            block[i / 3][j / 3] |= triance;
            bool if_success = dfs(next_i, next_j, board);
            if (if_success) {
                board[i][j] = '0' + view(triance);
                return true;
            }
            forbidden |= triance;
            rows[i] ^= triance;
            cols[j] ^= triance;
            block[i / 3][j / 3] ^= triance;
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {

        // 冷启动
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                unsigned char val = board[i][j] - '0' - 1;
                unsigned int set_flag = 0x01 << val;
                rows[i] |= set_flag;
                cols[j] |= set_flag;
                block[i / 3][j / 3] |= set_flag; 
            }
        }
        dfs(0, 0, board);
        return;
    }
};