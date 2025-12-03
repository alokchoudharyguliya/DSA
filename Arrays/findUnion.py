class Solution:
    def findUnion(self,arr1,arr2,n,m):
        freq={}
        for i in range(n):
            freq[arr1[i]]=freq.get(arr1[i],0)+1
        
        for i in range(m):
            freq[arr2[i]]=freq.get(arr2[i],0)+1

        Union=sorted(freq.keys())
        return Union


if __name__=="__main__":
    n=10
    m=7
    arr1=[1,2,3,4,5,6,7,8,9,10]
    arr2=[2,3,4,4,5,11,12]
    obj=Solution()
    Union=obj.findUnion(arr1,arr2,n,m)
    print(*Union)