class Trie {
    public Trie[] next = new Trie[26];
    public boolean isEnd = false;
    public Trie() {}
}

public class WordDictionary {
    private Trie root = new Trie();

    public WordDictionary() { }
    
    public void addWord(String word) {
        Trie node = root;
        for (int i = 0; i < word.length(); ++i) {
            int idx = word.charAt(i) - 'a';
            if (node.next[idx] == null) {
                node.next[idx] = new Trie();
            }
            node = node.next[idx];
        }
        node.isEnd = true;
    }
    
    private boolean dfs(Trie node, int idx, String word) {
        if (idx == word.length()) {
            return node.isEnd;
        }
        if (word.charAt(idx) == '.') {
            for (int i = 0; i < node.next.length; ++i) {
                if (node.next[i] != null && dfs(node.next[i], idx + 1, word))
                    return true;
            }
            return false;
        }
        if (null == node.next[word.charAt(idx) - 'a'])
            return false;
        return dfs(node.next[word.charAt(idx) - 'a'], idx + 1, word);
    }

    public boolean search(String word) {
        return dfs(root, 0, word);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */ 