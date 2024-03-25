import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    private String hashVal(String str) {
        StringBuilder retStr = new StringBuilder();
        int diff = str.charAt(0) - 'a' + 1;
        for (int i = 0; i < str.length(); ++i) {
            int addCh = str.charAt(i) - diff;
            if (addCh < 'a') addCh += 'z' - 'a' + 1;
            retStr.append(addCh);
        }
        return retStr.toString();
    }
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> groupHash = new HashMap<>();
        for (int i = 0; i < strings.length; ++i) {
            String hVal = hashVal(strings[i]);
            if (!groupHash.containsKey(hVal)) {
                groupHash.put(hVal, new ArrayList<String>());
            }
            groupHash.get(hVal).add(strings[i]);
        }
        List<List<String>> retList = new ArrayList<>();
        for (String key : groupHash.keySet()) {
            retList.add(groupHash.get(key));
        }
        return retList;
    }
}