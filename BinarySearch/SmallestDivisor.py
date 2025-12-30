import math
# Given array, divide the array with any positive integer, such that the sum of division's result is less than or equal to the given threshold value
# arr=[1,2,3,4,5], limit=8
# low will be 1 or smallest of arr, high will be the largest number
class Solution:
    # def smallestDivisor(self, arr, limit):
    #     high=max(arr)
        
    #     for i in range(1,high+1):
    #         total=0
    #         for num in arr:
    #             total+=math.ceil(num/i)
    #         if total<=limit:
    #             return i
    #     return -1
    def sumByD(self,arr:list,check:int):
        return sum(math.ceil(x/check) for x in arr)
        
    def smallestDivisor(self,arr,limit)->int:
        low=1
        high=max(arr)
        while low<=high:
            mid=(low+high)//2        
            if self.sumByD(arr,mid)<=limit:
                high=mid-1
                # we want the sum to be lesser than or equal to so, to lower the sum, we want to increase the divisors, and so low=mid+1
            else:
                low=mid+1
        return high
arr=[1,2,3,4,5]
limit=8
obj=Solution()
ans=obj.smallestDivisor(arr,limit)
print(ans)