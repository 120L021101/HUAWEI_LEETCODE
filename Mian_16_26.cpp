class Solution {
private:
    unordered_map<char, int> order_map {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    void clear(vector<int>& suffix, vector<char>& opStack, int order) {
        decltype(opStack.size()) size = opStack.size();
        int currentOrder;
        char top_c;
        while (size && order <= order_map[top_c = opStack[size - 1]]) {
            opStack.pop_back();
            suffix.push_back(-top_c);
            --size;
        }
    }
    void newNumber(vector<int>& suffix, string& readNumber) {
        if (readNumber.length()) {
            suffix.push_back(stoi(readNumber));
            readNumber.clear();
        }
    }
    int digitOpBlank(char c) {
        if ('0' <= c && c <= '9')
            return 1;
        if (c == ' ')
            return 2;
        return 3;
    }

public:
    int calculate(string s) {
        vector<int> suffix;
        vector<char> opStack;
        string readNumber;
        for (char c : s) {
            switch (digitOpBlank(c))
            {
            case 3:
                newNumber(suffix, readNumber);
                clear(suffix, opStack, order_map[c]);
                opStack.push_back(c);
                break;
            
            case 1:
                readNumber += c;
                break;

            case 2:
                newNumber(suffix, readNumber);
                break;
            }
        }
        newNumber(suffix, readNumber);
        clear(suffix, opStack, 0);

        vector<int> calculated_vals;
        for (int val : suffix) {
            if (val >= 0) {
                calculated_vals.push_back((int)val);
                continue;
            }
            char op = (char)(-val);
            decltype(calculated_vals.size()) size = calculated_vals.size();
            switch (op)
            {
            case '+':
                calculated_vals[size - 2] += calculated_vals[size - 1];
                break;
            case '-':
                calculated_vals[size - 2] -= calculated_vals[size - 1];
                break;
            case '*':
                calculated_vals[size - 2] *= calculated_vals[size - 1];
                break;
            case '/':
                calculated_vals[size - 2] /= calculated_vals[size - 1];
                break;
            }
            calculated_vals.pop_back();
        }
        return calculated_vals[0];
    }
};