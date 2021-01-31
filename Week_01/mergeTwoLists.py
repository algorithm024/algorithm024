# Definition for singly-linked list.
#class ListNode(object):
#    def __init__(self, val=0, next=None):
#        self.val = val
#        self.next = next

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        l3 = ListNode(object)
        pre = l3   
        while l1 and l2:
            if l1.val  <= l2.val:
                l3.next = l1
                l1=l1.next
            else:
                l3.next = l2
                l2=l2.next
            l3=l3.next
        l3.next = l1 if l1 is not None  else l2

        return pre.next
