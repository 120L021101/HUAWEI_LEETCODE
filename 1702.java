class Solution {
    public String maximumBinaryString(String binary) {
        StringBuilder sb = new StringBuilder();
        if (binary.equals("01")) {
            return binary;
        }
        int idx = 0;
        while (idx < binary.length() && binary.charAt(idx) == '1') {
            sb.append('1');
            idx ++;
        }

        int zeroCount = 0;
        for (int i = idx; i < binary.length(); ++i) {
            if (binary.charAt(i) == '0') {
                zeroCount += 1;
            }
        }
        for (int i = 0; i < zeroCount - 1; ++i) {
            sb.append('1');
        }
        if (zeroCount >= 1)
            sb.append('0');
        for (int i = 0; i < binary.length() - idx - zeroCount; ++i) {
            sb.append('1');
        }
        return sb.toString();
    }
}