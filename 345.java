import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public String reverseVowels(String s) {
        Set<Character> vowel = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));
        int l = 0, r = s.length() - 1;
        Character[] str = new Character[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            str[i] = s.charAt(i);
        }
        while (l < r) {
            while (!vowel.contains(str[l]) && l < r) {
                l++;
            }
            while (!vowel.contains(str[r]) && l < r) {
                r--;
            }
            Character temp = str[l];
            str[l] = str[r];
            str[r] = temp;
            l ++;
            r --;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < str.length; ++i) {
            sb.append(str[i]);
        }
        return sb.toString();
    }
}