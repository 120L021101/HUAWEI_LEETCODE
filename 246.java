class Solution {
    public boolean isStrobogrammatic(String num) {
        Map<Character, Character> numMap = new HashMap<>();
        numMap.put('1', '1');
        numMap.put('6', '9');
        numMap.put('9', '6');
        numMap.put('8', '8');
        numMap.put('0', '0');
        int i = 0, j = num.length() - 1;
        while (i <= j) {
            if (!numMap.containsKey(num.charAt(i)))
                return false;
            if (!numMap.containsKey(num.charAt(j)))
                return false;
            if (numMap.get(num.charAt(i)) != num.charAt(j))
                return false;
            i ++;
            j --;
        }
        return true;
    }
}