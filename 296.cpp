class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x = {};
        vector<int> y = {};
        unsigned int count = 0;
        decltype(grid.size()) row = grid.size();
        decltype(grid.size()) col = grid[0].size();
        for (int i = 0; i != row; ++i) {
            for (int j = 0; j != col; ++j) {
                if (grid[i][j]) {
                    count ++;
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        sort(x.begin(), x.end(), [](int a, int b) {return a < b;});
        sort(y.begin(), y.end(), [](int a, int b) {return a < b;});
        int mid_x = x[x.size() / 2];
        int mid_y = y[y.size() / 2];
        int x_loss = 0;
        int y_loss = 0;
        for (int x_val : x) {
            x_loss += abs(x_val - mid_x);
        }
        for (int y_val : y) {
            y_loss += abs(y_val - mid_y);
        }
        return x_loss + y_loss;
    }
};