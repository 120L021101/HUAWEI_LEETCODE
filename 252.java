
class Solution {
    public boolean canAttendMeetings(int[][] intervals) {
        if (intervals.length == 0) return true;
        List<List<Integer>> list_intervals = new ArrayList<>();
        for (int i = 0; i < intervals.length; ++i) {
            list_intervals.add(Arrays.asList(intervals[i][0], intervals[i][1]));
        }
        Collections.sort(list_intervals, new Comparator<List<Integer>>() {
            @Override
            public int compare(List<Integer> arg0, List<Integer> arg1) {
                return arg0.get(0).compareTo(arg1.get(0));
            }
        });
        for (int i = 1; i < list_intervals.size(); ++i) {
            if (list_intervals.get(i).get(0) < list_intervals.get(i - 1).get(1))
                return false;
        }
        return true;
    }
}