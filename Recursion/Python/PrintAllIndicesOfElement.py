def helper(l1,x,ind):
    if(len(l1)==ind):
        return
    helper(l1,x,ind+1)
    if(l1[ind]==x):
        print(ind)
def printAllIndicesOfELement(l1,x):
    helper(l1,x,0)

printAllIndicesOfELement([3,2,5,2,8,2,1],2)