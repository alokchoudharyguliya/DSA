def ReturnAllIndicesAsAList(l1,index):
    if(len(l1)==index):
        return []
    smallList=ReturnAllIndicesAsAList(l1,index+1)
    if(l1[index]==x):
        smallList.insert(0,index)
    return smallList

l1=[3,2,5,2,8,2,1]
ansList=ReturnAllIndicesAsAList(l1,0)
print(ansList)