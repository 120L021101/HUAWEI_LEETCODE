class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        deque<vector<int>> levels;
        unsigned int empty_room = ((unsigned int)0x1 << 31) - 1;
        int n = rooms.size(), m = rooms[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    levels.push_back({i, j, 0});
                }
            }
        }
        while (int size = levels.size()) {
            for (int t = 0; t < size; ++t) {
                int i = levels[0][0], j = levels[0][1], distance = levels[0][2];
                if (i && rooms[i - 1][j] == empty_room) {
                    rooms[i - 1][j] = distance + 1;
                    levels.push_back({i - 1, j, distance + 1});
                }
                if (j && rooms[i][j - 1] == empty_room) {
                    rooms[i][j - 1] = distance + 1;
                    levels.push_back({i, j - 1, distance + 1});
                }
                if (i < n - 1 && rooms[i + 1][j] == empty_room) {
                    rooms[i + 1][j] = distance + 1;
                    levels.push_back({i + 1, j, distance + 1});
                }
                if (j < m - 1 && rooms[i][j + 1] == empty_room) {
                    rooms[i][j + 1] = distance + 1;
                    levels.push_back({i, j + 1, distance + 1});
                }
                levels.pop_front();
            }
        }
    }
};