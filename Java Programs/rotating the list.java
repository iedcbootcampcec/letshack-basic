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
if (head == null || head.next == null || k == 0) return head;
    int size = 0;
    ListNode tail = null;
    ListNode curr = head;
    // Size and get tail pointer whose next is present head in same iteration
    while (curr != null) {
        tail = curr;
        curr = curr.next;
        size++;
    }
    // Next itr ready
    curr = head;
    // Got size, rectify k > size condition with modulo
    k = k % size;
    // Till size - k, for k-1 and k elem pointer
    int pointer = 1;
    // Attach tails pointer to head, wont go in infinite loop as 0 is handled beforehand
    tail.next = head;
    while (curr.next != null) {
        // Only when pointer in correct position, ie just before k,
        // Do pointer updations, can also be done out of while loop
        if (pointer == size - k) {
            // Instead of a new var, head var reused
            head = curr.next;
            curr.next = null;
            break;
        }
        curr = curr.next;
        pointer++;
    }
    return head;
}
}