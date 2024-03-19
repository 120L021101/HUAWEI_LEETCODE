class Solution {
private:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    int partition(vector<int>& arr, int s, int e) {
        int pivot = arr[s];
        int idx = s + 1;
        for (int i = s + 1; i < e; ++i) {
            if (arr[i] < pivot) {
                swap(arr[i], arr[idx++]);
            }
        }
        swap(arr[idx - 1], arr[s]);
        return idx - 1;
    }
    void sort(vector<int>& arr, int s, int e, int k) {
        int p = partition(arr, s, e);
        if (p < k) sort(arr, p + 1, e, k);
        else if (p > k) sort(arr, s, p, k);
    }
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() == 0) return {};
        sort(arr, 0, arr.size(), k);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
};