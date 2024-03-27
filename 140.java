import java.util.LinkedList;

class Trie {
    public String word = null;
    public Trie[] next = new Trie[26];
    public boolean isEnd = false;
}
class Solution {
    public void dfs(String s, StringBuilder currentStr, List<String> sentences, Trie node, Trie root, int i) {
        if (i == s.length()) {
            if (node.isEnd) {
                int length = currentStr.length();
                currentStr.append(String.format("%s", node.word));
                sentences.add(currentStr.toString());
                currentStr.delete(length, currentStr.length());
            }
            return;
        }
        int idx = s.charAt(i) - 'a';
        if (node.next[idx] != null) {
            dfs(s, currentStr, sentences, node.next[idx], root, i + 1);                
        }
        if (node.isEnd && root.next[idx] != null) {
            int length = currentStr.length();
            currentStr.append(String.format("%s ", node.word));
            dfs(s, currentStr, sentences, root.next[idx], root, i + 1);
            currentStr.delete(length, currentStr.length());
        }
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        Trie root = new Trie();
        for (String word : wordDict) {
            Trie node = root;
            for (int i = 0; i < word.length(); ++i) {
                int idx = word.charAt(i) - 'a';
                if (node.next[idx] == null) {
                    node.next[idx] = new Trie();
                }
                node = node.next[idx];
            }
            node.isEnd = true;
            node.word = word;
        }
        List<String> retStr = new LinkedList<>();
        dfs(s, new StringBuilder(), retStr, root, root, 0);
        return retStr;
    }
}