class Solution {
    public int compress(char[] chars) {
        int pointer = 0;
        int count = 1;
        for (int i = 1; i < chars.length; ++i) {
            if (chars[i] == chars[pointer]) {
                count ++;
                continue;
            }
            pointer ++;
            if (count == 1) {
                chars[pointer] = chars[i];
                continue;
            }
            String occur = Integer.toString(count);
            for (int j = 0; j < occur.length(); ++j) {
                chars[pointer ++] = occur.charAt(j);
            }
            chars[pointer] = chars[i];
            count = 1;
        }
        pointer ++;
        if (count != 1) {
            String occur = Integer.toString(count);
            for (int j = 0; j < occur.length(); ++j) {
                chars[pointer ++] = occur.charAt(j);
            }
        }
        return pointer;
    }
}