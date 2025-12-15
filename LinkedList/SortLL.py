class Node:
    def __init__(self, data1, next1=None):
        self.data=data1
        self.next=next1

class Solution:
    def mergeTwoSortedLinkedLists(self, list1, list2):
        dummyNode=Node(-1)
        temp=dummyNode
        
        while list1 and list2:
            if list1.data<=list2.data:
                temp.next=list1
                list1=list1.next
            else:
                temp.next=list2
                list2=list2.next
            temp=temp.next
        if list1:
            temp.next=list1
        else:
            temp.next=list2
        
        return dummyNode.next

    def findMiddle(self,head):
        if not head or not head.next:
            return head
        slow=head
        fast=head.next
        while fast and fast.next:
            slow=slow.next
            fast=fast.next.next
        return slow
    
    def sortLL(self,head):
        if not head or not head.next:
            return head
        middle=self.findMiddle(head)
        right=middle.next
        middle.next=None
        left=head
        left=self.sortLL(left)
        right=self.sortLL(right)

        return self.mergeTwoSortedLinkedLists(left,right)
    
def printLinkedList(head):
    temp=head
    while temp:
        print(temp.data, end=" ")
        temp=temp.next
    print()


if __name__=="__main__":
    head=Node(3)
    head.next=Node(2)
    head.next.next=Node(5)
    head.next.next.next=Node(4)
    head.next.next.next.next=Node(1)
    printLinkedList(head)
    obj=Solution()
    head=obj.sortLL(head)
    printLinkedList(head)
