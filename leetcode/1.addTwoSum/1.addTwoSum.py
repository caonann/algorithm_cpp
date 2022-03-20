#https://leetcode-cn.com/problems/add-two-numbers/submissions/
import pdb
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

print(dir(ListNode))
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = l= ListNode()
        carry=0
        list1 = l1
        list2 = l2
        while list1 and list2:
            _=list1.val+list2.val
            if _ >=10:
                l.next = ListNode(_%10+carry)
                carry = 1
            else:
                if _+carry >=10:
                    l.next = ListNode((_+carry)%10)
                    carry=1
                else:
                    l.next = ListNode(_+carry)
                    carry=0
            l=l.next
            list1=list1.next
            list2=list2.next
        
        def tmpfunc(list_tmp,l,carry):
            while list_tmp:
                #pdb.set_trace()
                _ = list_tmp.val+carry
                if _ >=10:
                    l.next=ListNode(_%10)
                    carry = 1 
                else:
                    l.next = ListNode(_)
                    carry=0
                l=l.next
                list_tmp = list_tmp.next
            return l,carry

        if list1:
            l,carry = tmpfunc(list1,l,carry)
        if list2:
            l,carry = tmpfunc(list2,l,carry)
        if carry >=1:
            l.next=ListNode(1)
        return head.next
    def addTwoNumbersV2(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = curr = ListNode()
        carry = val = 0
        while carry or l1 or l2:
            val = carry

            if l1: l1, val = l1.next, l1.val + val
            if l2: l2, val = l2.next, l2.val + val

            carry, val = divmod(val, 10)
            curr.next = curr = ListNode(val)
        
        return head.next

def printListNodes(l):
    ret = []
    while l:
        ret.append(str(l.val))
        l = l.next
    print(','.join(ret))

if __name__ == "__main__":
    s = Solution()
    head1=l1 = ListNode(9)
    head2=l2 = ListNode(9)
    for i in range(7):
        l1.next=ListNode(9)
        l1 = l1.next
    for i in range(4):
        l2.next = ListNode(9)
        l2 = l2.next
    
    printListNodes(head1)
    printListNodes(head2)
    l = s.addTwoNumbersV2(head1,head2)
    printListNodes(l)

    