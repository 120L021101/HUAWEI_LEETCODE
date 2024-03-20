class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> occurCharacters = new HashSet<>();
        int begin = 0, end = 0;
        int maxLength = 0;
        while (end != s.length()) {
            while (occurCharacters.contains(s.charAt(end))) {
                occurCharacters.remove(s.charAt(begin));
                begin += 1;
            }
            occurCharacters.add(s.charAt(end));
            end += 1;
            maxLength = Math.max(maxLength, end - begin);
        }
        return maxLength;
    }
}