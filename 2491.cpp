class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        if (skill.size() % 2) return -1;
        long long sum = 0;
        for (vector<int>::iterator itr = skill.begin(), end = skill.end(); itr != end; itr ++) {
            sum += *itr;
        }        
        int average_alloc = (sum * 2) / skill.size();
        if ((sum * 2) % skill.size()) return -1;
        sort(skill.begin(), skill.end(), [](int& a, int& b) {return a < b;});
        long long prodcut = 0;
        for (vector<int>::iterator itr_b = skill.begin(), itr_e = skill.end() - 1; itr_b != itr_e + 1; itr_b++, itr_e--) {
            // cout << *itr_b << ' ' << *itr_e << endl;
            if (*itr_b + *itr_e != average_alloc)
                return -1;
            prodcut += (*itr_b * *itr_e);
        }
        return prodcut;
    }
};