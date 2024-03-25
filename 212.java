
class Trie {
    public Trie[] next = new Trie[26];
    public String word = null;
    public Trie() {}
}


class Solution {

    private void dfs(List<String> rightWord, char[][] board, boolean[][] visited, Trie node, int x, int y) {
        
        if (x == -1 || y == -1 || x == board.length || y == board[0].length)
            return;
        if (visited[x][y]) return;
        int idx = board[x][y] - 'a';
        if (node.next[idx] == null) return;
        node = node.next[idx];
        if (node.word != null) {
            rightWord.add(node.word);
            node.word = null;
        }
        visited[x][y] = true;
        dfs(rightWord, board, visited, node, x, y - 1);
        dfs(rightWord, board, visited, node, x, y + 1);
        dfs(rightWord, board, visited, node, x - 1, y);
        dfs(rightWord, board, visited, node, x + 1, y);
        visited[x][y] = false;
    }

    public List<String> findWords(char[][] board, String[] words) {
        Trie root = new Trie();
        for (String word : words) {
            Trie node = root;
            for (int i = 0; i < word.length(); ++i) {
                int idx = word.charAt(i) - 'a';
                if (null == node.next[idx]) {
                    node.next[idx] = new Trie();
                }
                node = node.next[idx];
            }
            node.word = word;
        }
        List<String> rightWord = new LinkedList<>();
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                dfs(rightWord, board, new boolean[board.length][board[0].length], root, i, j);
            }
        }
        return rightWord;
    }
}