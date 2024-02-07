class Solution {
public:
    string crackPassword(vector<int>& password) {
        sort(password.begin(), password.end(), [](int a, int b){
            string &&str_a = to_string(a), &&str_b = to_string(b);
            return move(str_a + str_b) < move(str_b + str_a);
        });
        string ret;
        for (int& i : password) {
            ret += to_string(i);
        }
        return ret;
    }
};