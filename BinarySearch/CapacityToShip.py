# n=5, weights=[], d=5
# find the minimum capacity of the ship such that all packages can be shipped within d days, check every capacity starting from the maximum single package weight(since capacity can't be less than the heaviest package) up to sum of all package weights(which guarantees all packages shipped in one day)
# find the smallest capacity that ships all packages in <=d days
class Solution:
    def daysNeeded(self,weights,cap):
        days=1
        currentLoad=0
        for w in weights:
            if currentLoad+w>cap:
                days+=1
                currentLoad=w
            else:
                currentLoad+=w
        return days
    
    def shipWithinDays(self,weights,d):
        low=max(weights)
        high=sum(weights)
        # for capacity in range(low, high+1):
        #     needed=self.daysNeeded(weights,capacity)
        #     if needed<=d:
        #         return capacity
        # return high
        while low<high:
            mid=low+(high-low)//2
            if self.daysNeeded(weights,mid)<=d:
                high=mid
            else:
                low=mid+1
        return low

# if __name__=="__main__":
sol=Solution()
weights=[5,4,5,2,3,4,5,6]
d=5
print(sol.shipWithinDays(weights,d))