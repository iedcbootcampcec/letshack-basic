#Class to create a linked list
class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
#Class for functions on linked list
class Solution(object):
    #Function to remove duplicates from a sorted linked list
    def deleteDuplicates(self, head):
        temp = head
        if temp is None:
            return
        while temp.next is not None:
            if temp.val == temp.next.val:
                new = temp.next.next
                temp.next = None
                temp.next = new
            else:
                temp = temp.next
        return head