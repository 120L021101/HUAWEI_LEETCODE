/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

 class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int C = 0;
        ListNode retNode = new ListNode(0), curPointer = retNode;
        while (l1 != null || l2 != null || C != 0) {
            int val = 0;
            if (l1 != null) {
                val += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                val += l2.val;
                l2 = l2.next;
            }
            val += C;
            if (val >= 10) {
                C = 1;
                val -= 10;
            }
            else {
                C = 0;
            }
            curPointer.next = new ListNode(val);
            curPointer = curPointer.next;
        }
        return retNode.next;
    }
}