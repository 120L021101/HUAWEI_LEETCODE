class Solution {
private:
    int view(unsigned int val) {
        int digit = 0;
        while (val >>= 1)
            digit ++;
        return digit;
    }
    bool getOrder(string& a, string& b, int& father, int& child) {
        int minLength = min(a.length(), b.length());
        for (int i = 0; i < minLength; ++i) {
            if (a[i] == b[i]) continue;
            father = a[i] - 'a';
            child = b[i] - 'a';
            return true;
        }
        if (a.length() > b.length()) return false;
        father = child = 'a';
        return true;
    }
public:
    string alienOrder(vector<string>& words) {
        unsigned int father[26] = { 0 };
        unsigned int child[26] = { 0 };
        unsigned int alive = 0;
        for (auto before = words.begin(), after = before + 1, end = words.end(); 
                after != end; before++, after++) {
            int f, c;
            if (!getOrder(*before, *after, f, c))
                return "";
            if (f != c) {
                father[c] |=  0x01 << f;
                child[f] |= 0x01 << c;
            }
        }
        for (string& word : words) {
            for (char c : word) {
                alive |= 0x1 << c - 'a';
            }
        }
        string return_str = "";
        while (alive) {
            int all_nodes = alive;
            int triance = 0, triance_idx = 0;
            while (all_nodes) {
                triance = all_nodes & (-all_nodes);
                triance_idx = view(triance);
                if (!father[triance_idx])
                    break;
                all_nodes ^= triance;
                triance_idx = -1;
            }
            if (triance_idx == -1) break;

            int childrens = child[triance_idx];
            while (childrens) {
                int pick_child = (childrens) & (-childrens);
                father[view(pick_child)] ^= triance;
                childrens ^= pick_child;
            }
            child[triance_idx] = 0;
            return_str += 'a' + triance_idx;
            alive ^= triance;
        }
        if (alive) {
            return "";
        }
        return return_str;
    }
};