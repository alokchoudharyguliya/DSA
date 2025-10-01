def firstIndexOfElement(l1,ele):
    if(len(l1)==0):
        return -1
    if(l1[0]==ele):
        return 0
    ans=firstIndexOfElement(l1[1:],ele)
    if(ans==-1):
        return ans
    else:
        return ans+1
def lastIndexOfElement(l1,ele):

    if(len(l1)-1<0):
        return -1
    if(l1[len(l1)-1]==ele):
        return len(l1)-1
    return lastIndexOfElement(l1[:len(l1)-1],ele)

print(firstIndexOfElement([3,2,5,2,8,2,1],2))
print(lastIndexOfElement([3,2,5,2,8,2,1],2))