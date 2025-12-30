class Solution:
    # def nRoot(self,n:int, m:int)-> int:
    #     # n is the root value
    #     # m is the number to find the root of, the value of the nth root will for sure be lesser than m
    #     s,l=1,m
    #     # while s<m:
    #     for i in range(1,m+1):
    #         power=i**n
    #         if power==m:
    #             return i
            
    #         if power>m:
    #             break
    #     return -1
    def nRoot(self,n:int, m:int)-> int:
    # start with range of 1 to m, find the middle value in this range, obtain its nth power
    # then shift according to the value of mid and the given m value
        left, right=1,m
        while left<=right:
            mid=(left+right)//2
            # val=mid**n
            ans=1
            for _ in range(n):
                ans*=mid
                if ans>m:
                    break
            
            if ans<m:
                left=mid+1
            elif ans>m:
                right=mid-1
            else:
                return mid
        return -1
if __name__=="__main__":
    sol=Solution()
    print(sol.nRoot(6,64))