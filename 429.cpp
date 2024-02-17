/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {

private:
    void swap(vector<Node *> *&val1, vector<Node *> *&val2) {
        vector<Node *> * temp = val2;
        val2 = val1;
        val1 = temp;
    }

public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> levels;
        vector<Node *> level1 { root }, level2;
        vector<Node *>* this_level = &level1, * next_level = &level2;
        while (!this_level->empty()) {
            levels.push_back({});
            auto pointer = levels.end() - 1;
            for (Node *& node : *this_level) {
                pointer->push_back(node->val);
                for (Node *& child : node->children) {
                    next_level->push_back(child);
                }
            }
            this_level->clear();
            swap(this_level, next_level);
        }
        return levels;
    }
};