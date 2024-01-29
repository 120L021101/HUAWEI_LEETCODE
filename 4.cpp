class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum_length = nums1.size() + nums2.size();
        int find_index = (sum_length + 1) >> 1;
        int list1_start = 0, list2_start = 0;
        while (find_index != 1) {
            int alloc1 = find_index >> 1, remaining1 = nums1.size() - list1_start;
            int alloc2 = find_index >> 1, remaining2 = nums2.size() - list2_start;
            if      (alloc1 > remaining1)  alloc1 = remaining1;
            else if (alloc2 > remaining2)  alloc2 = remaining2;
            
            if (!alloc1) {
                list2_start += alloc2;
                find_index -= alloc2;
                continue;
            }
            if (!alloc2) {
                list1_start += alloc1;
                find_index -= alloc1;
                continue;
            }
            
            int val1 = nums1[list1_start + alloc1 - 1];
            int val2 = nums2[list2_start + alloc2 - 1];
            if (val1 >= val2) {
                list2_start += alloc2;
                find_index -= alloc2;
            } else {
                list1_start += alloc1;
                find_index -= alloc1;
            }
        }
        
        if (sum_length % 2 == 1) {
            if (nums1.size() == list1_start) return (double)nums2[list2_start];
            if (nums2.size() == list2_start) return (double)nums1[list1_start];
            return (double)min(nums1[list1_start], nums2[list2_start]);
        }
        int this_val, next_val;
        if (nums1.size() == list1_start) {
            this_val = nums2[list2_start];
            next_val = nums2[list2_start + 1];
        }
        else if (nums2.size() == list2_start) {
            this_val = nums1[list1_start];
            next_val = nums1[list1_start + 1];
        }
        else {
            this_val = min(nums1[list1_start], nums2[list2_start]);
            if (nums1[list1_start] == this_val) list1_start ++;
            else list2_start ++;
            if (nums1.size() == list1_start) next_val = nums2[list2_start];
            else if (nums2.size() == list2_start) next_val = nums1[list1_start];
            else next_val = min(nums1[list1_start], nums2[list2_start]);
        }
        return ((double)this_val + next_val) / 2;
    }
};