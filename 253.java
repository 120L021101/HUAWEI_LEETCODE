
class Solution {
    public int minMeetingRooms(int[][] intervals) {
        List<List<Integer>> list_intervals = new ArrayList<>();
        for (int i = 0; i < intervals.length; ++i) {
            list_intervals.add(Arrays.asList(intervals[i][0], 1));
            list_intervals.add(Arrays.asList(intervals[i][1], -1));
        }
        Collections.sort(list_intervals, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> arg0, List<Integer> arg1) {
                return arg0.get(0).compareTo(arg1.get(0));
            }
        });
        Map<Integer, Integer> count = new TreeMap<>();
        for (List<Integer> ls : list_intervals) {
            int key = ls.get(0), val = ls.get(1);
            count.put(key, count.getOrDefault(key, 0) + val);
        }
        list_intervals.clear();
        for (Integer key : count.keySet())
            list_intervals.add(Arrays.asList(key, count.get(key)));
        int maxNum = 0, curNum = 0;
        for (int i = 0; i < list_intervals.size(); ++i) {
            curNum += list_intervals.get(i).get(1);
            maxNum = Math.max(maxNum, curNum);
        }
        return maxNum;
    }
}