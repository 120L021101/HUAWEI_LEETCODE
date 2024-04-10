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
    public ListNode reverseList(ListNode head) {
        ListNode header = new ListNode(0, (ListNode)null);
        ListNode pointer = head, next = null;
        while (pointer != null) {
            next = pointer.next;
            pointer.next = header.next;
            header.next = pointer;
            pointer = next;
        }
        return header.next;
    }
}