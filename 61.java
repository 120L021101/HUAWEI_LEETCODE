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
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return head;
        int length = 0;
        ListNode countLength = head;
        while (countLength != null) {
            countLength = countLength.next;
            length ++;
        }
        k %= length;
        ListNode header = new ListNode(-1, head);
        ListNode slow = head, fast = head;
        for (int i = 0; i < k; ++i) {
            fast = fast.next;
        }
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        fast.next = header.next;
        header.next = slow.next;
        slow.next = null;
        return header.next;
    }
}