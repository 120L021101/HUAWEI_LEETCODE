class TrieNode {
private:
    char isEnd = 0;
    char this_ch = 0;
    TrieNode* next[26];
public:
    TrieNode() {
        memset(next, 0, sizeof(TrieNode *) * 26);
    }
    TrieNode(char ch) : this_ch(ch) {
        memset(next, 0, sizeof(TrieNode *) * 26);
    }
    TrieNode* insert(char c) {
        char idx = c - 'a';
        if (next[idx]) 
            return next[idx];
        return (next[idx] = new TrieNode(c));
    }
    TrieNode* go(char c) {
        return next[c - 'a'];
    }
    void setEnd() { isEnd = true; }
    bool ifEnd() { return isEnd; }
};

class Trie {
private:
    TrieNode root = TrieNode();
    TrieNode* gotoEnd(string &str) {
        TrieNode *p = &root;
        for (char c : str) {
            p = p->go(c);
            if (p == nullptr)
                return nullptr; 
        }
        return p;
    }
public:
    Trie() { }
    
    void insert(string word) {
        TrieNode *p = &root;
        for (char c : word) {
            p = p->insert(c);
        }
        p->setEnd();
    }
    
    bool search(string word) {
        TrieNode * end = this->gotoEnd(word);
        return (end && end->ifEnd());
    }
    
    bool startsWith(string prefix) {
        return this->gotoEnd(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */