class Solution {

private:

    unsigned int av_col;
    unsigned int av_l;
    unsigned int av_r;
    
    int dfs(int row, int n) {
        if (n == row) {
            return 1;
        }
        int count = 0;
        unsigned int cols = av_col & ( av_l >> (n - 1 - row) ) & ( av_r >> row );
        while (cols) {
            unsigned int pick = cols & -cols;
            av_col ^= pick;
            av_l ^= pick << (n - 1 - row);
            av_r ^= pick << row;

            count += dfs(row + 1, n);

            av_col |= pick;
            av_l |= pick << (n - 1 - row);
            av_r |= pick << row;

            cols -= pick;   
        }
        return count;
    }

public:
    int totalNQueens(int n) {
        av_col = (0x1 << n) - 1;
        av_l = (0x1 << (2 * n - 1)) - 1;
        av_r = av_l;
        return dfs(0, n);
    }
};