class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> decreasing_stack;
        int accumulated_water = 0;
        for (int i = 0; i < height.size(); ++i) {
            int last_height = 0;
            while (int size = decreasing_stack.size()) {
                pair<int, int>& front_col = decreasing_stack[size - 1];
                int h = front_col.first, idx = front_col.second;
                if (h <= height[i]) {
                    accumulated_water += (h - last_height) * (i - idx - 1);
                    last_height = h;
                    decreasing_stack.pop_back();
                }
                else {
                    accumulated_water += (height[i] - last_height) * (i - idx - 1); 
                    break;
                }
            }
            decreasing_stack.push_back({height[i], i});
        }
        // TODO
        return accumulated_water;
    }
};