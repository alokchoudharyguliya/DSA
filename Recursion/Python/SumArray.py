def sumArray(l1):
    if(not len(l1)):
       return 0
    ans=l1[0]+sumArray(l1[1:])
    print(l1[0])
    return ans

print(sumArray([1,2,3,4,5])) 
