class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string z_s = "";
        int period = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i) {
            int first_index = i;
            int second_index = (period - i) % period;
            bool if_dup = first_index == second_index;
            while (first_index < s.length()) {
                z_s += s[first_index];
                first_index += period;
                if (!if_dup && second_index < s.length()) {
                    z_s += s[second_index];
                }
                second_index += period;
            }
        }
        return z_s;
    }
};