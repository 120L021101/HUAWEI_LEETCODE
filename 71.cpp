class Solution {

private:
    void split(const string& str, const char delim, vector<string>& split_ls) {
        string current = "";
        for (char ch : str) {
            if (ch == delim) {
                if (current.length())
                    split_ls.push_back(move(current));
                current.clear();
            }
            else {
                current += ch;
            }
        }
        if (current.length())
            split_ls.push_back(move(current));
    }

public:
    string simplifyPath(string path) {
        vector<string> split_ls;
        split(path, '/', split_ls);
        vector<string> item_stack;
        for (string& item : split_ls) {
            if (item == ".") {
                continue;
            }
            else if (item == "..") {
                if (item_stack.size()) {
                    item_stack.pop_back();
                }
            }
            else {
                item_stack.push_back(move(item));
            }
        }
        ostringstream out;
        for (string& item : item_stack) {
            out << "/" << item;
        }
        if (item_stack.size() == 0) {
            out << "/";
        }
        return out.str();
    }
};