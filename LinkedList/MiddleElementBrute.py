class Node:
    def __init__(self,data,next_node=None):
        self.data=data
        self.next=next_node

def find_middle(head):
    if head is None or head.next is None:
        return head
    temp=head
    count=0
    while temp is not None:
        count+=1
        temp=temp.next
    mid=count//2+1
    temp=head
    while temp is not None:
        mid=mid-1
        if mid==0:
            break
        temp=temp.next

    return temp
head=Node(1)
head.next=Node(2)
head.next.next=Node(3)
head.next.next.next=Node(4)
head.next.next.next.next=Node(5)
middle_node=find_middle(head)
print(middle_node.data)