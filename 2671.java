import java.util.HashMap;
import java.util.Map;

class FrequencyTracker {

    private Map<Integer, Integer> numberCount = new HashMap<>();
    private Map<Integer, Integer> frequencyHave = new HashMap<>();

    public FrequencyTracker() {}
    
    public void add(int number) {
        if (!numberCount.containsKey(number)) {
            numberCount.put(number, 1);
            frequencyHave.put(1, frequencyHave.getOrDefault(1, 0) + 1);
            return;
        }
        int prevFrequency = numberCount.get(number);
        int frequencyCount = frequencyHave.get(prevFrequency);
        if (frequencyCount != 1) {
            frequencyHave.put(prevFrequency, frequencyCount - 1);
        } else {
            frequencyHave.remove(prevFrequency);
        }
        frequencyHave.put(prevFrequency + 1, frequencyHave.getOrDefault(prevFrequency + 1, 0) + 1);
        numberCount.put(number, prevFrequency + 1);
    }
    
    public void deleteOne(int number) {
        if (!numberCount.containsKey(number)) return;
        int prevFrequency = numberCount.get(number);
        if (prevFrequency == 1) {
            numberCount.remove(number);
        } else {
            numberCount.put(number, prevFrequency - 1);
        }
        int frequencyCount = frequencyHave.get(prevFrequency);
        if (frequencyCount == 1) {
            frequencyHave.remove(prevFrequency);
        } else {
            frequencyHave.put(prevFrequency, frequencyCount - 1);
        }
        frequencyHave.put(prevFrequency - 1, frequencyHave.getOrDefault(prevFrequency - 1, 0) + 1);
    }
    
    public boolean hasFrequency(int frequency) {
        return frequencyHave.containsKey(frequency);
    }
}

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker obj = new FrequencyTracker();
 * obj.add(number);
 * obj.deleteOne(number);
 * boolean param_3 = obj.hasFrequency(frequency);
 */