class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> ret_matrix = matrix;
        vector<int> max_ls (matrix[0].size(), 0);
        for (int i = 0; i < ret_matrix.size(); ++i) {
            for (int j = 0; j < max_ls.size(); ++j) {
                if (ret_matrix[i][j] > max_ls[j]) {
                    max_ls[j] = ret_matrix[i][j];
                }
            }
        }
        for (int i = 0; i < ret_matrix.size(); ++i) {
            for (int j = 0; j < max_ls.size(); ++j) {
                if (ret_matrix[i][j] == -1) {
                    ret_matrix[i][j] = max_ls[j];
                }
            }
        }
        return ret_matrix;
    }
};