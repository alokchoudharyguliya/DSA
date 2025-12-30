# naive to check all possible answers from 1 to max(a[])
# Minimum number for which the required time is less than or equal to h
# find the largest pile size, max of array
# loop through all possible speeds from 1 to this maximum value

# for each speed, calculate the total hours needed, for each pile compute the time as ceil(pile/speed)
# sum up the hours for all piles
# if total hours is less than or equal to the allowed hours, return this speed as answer
import math
class Solution:
    # def calculateTotalHours(self,a,hourly):
    #     totalHours=0
    #     for pile in a:
    #         totalHours+=math.ceil(pile/hourly)
    #     print(totalHours)
    #     return totalHours
    # def minEatingSpeed(self, a:list[int], h:int)->int:
    #     maxVal=max(a) # returns the maximum element of the array

    #     for i in range(1, maxVal+1): # maxVal inclusive

    #         hours=self.calculateTotalHours(a,i)
    #         if hours<=h:
    #             return i
    #     return maxVal
    def calculateTotalHours(self,a:list,rate:int)->int:
        totalHours=0
        for i in a:
            totalHours+=math.ceil(i/rate)
        return totalHours
    def minEatingSpeed(self, a:list,h:int)->int:
        maxPile=max(a)
        low,high=1,maxPile
        while low<=high:
            mid=(low+high)//2
            totalH=self.calculateTotalHours(a, mid)
            if totalH<=h:
                ans=mid
                high=mid-1
            else:
                low=mid+1
        return ans
# The possible answer space from 1 to maximum pile size is sorted, meaning if a certain speed works, then all higher speeds will also work.
# This allows us to apply Binary Search on the answer space to efficiently find the minimum spped at which Koko can finish the bananas within the given hours
# at each step, take the middle value as the current speed and calculate how many hours it would take to fininsh all piles at this speed
# If the total hours are less than or equal to the allowed hours, this speed is a candidate, so try to see if a smaller speed also works by moving left
# If the toal hours exceed the allowed hours, then the speed is too slow, so move to right to try higher speeds, continue this process until the range closes, and the smallest valid speed found will be the answer
a=[3,6,7,11]
h=8
obj=Solution()
print(obj.minEatingSpeed(a,h))