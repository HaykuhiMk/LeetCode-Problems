# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def swapNodes(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        first = last = head
        for i in range(k - 1):
            first = first.next
        temp = first
        while temp.next:
            last = last.next
            temp = temp.next
        first.val, last.val = last.val, first.val
        return head
