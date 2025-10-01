def updateAllIndices(l1,val,ind,ansList):
    if(len(l1)==ind):
        return
    if(l1[ind]==val):
        ansList.append(ind)
    updateAllIndices(l1,val,ind+1,ansList=ansList)

ansList=[]
updateAllIndices([3,2,5,2,8,2,1],2,0,ansList)
print(ansList)
iterator=iter(ansList)
try:
    while True:
        print(next(iterator))
except StopIteration:
    pass