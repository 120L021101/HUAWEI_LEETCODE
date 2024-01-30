class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size() - 1;
        int max_area = 0;
        while (start < end) {
            max_area = max(max_area, min(height[start], height[end]) * (end - start));
            if (height[start] < height[end]) {
                start ++;
            } else {
                end --;
            }
        }
        return max_area;
    }
};