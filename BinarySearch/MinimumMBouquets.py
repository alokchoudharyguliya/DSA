class RoseGarden:
    def is_possible(self,bloom_days_array,day,m,k):
        count=0
        bouquets=0
        for bloom in bloom_days_array:
            if bloom<=day:
                count+=1
                if count==k:
                    bouquets+=1
                    count=0
            else:
                count=0
        return bouquets>=m
    def min_days_to_make_bouquets(self, bloom_days_array:list,m:int, k:int)->int:
        day=0
        total=len(bloom_days_array)
        required=m*k
        # check if we have enough flowers that is if the lenght of array is lesser than or equal to m*k => flowers required
        if total<required:
            return -1
        
        low=min(bloom_days_array)
        high=max(bloom_days_array)
        for day in range(low,high+1):
            if self.is_possible(bloom_days_array,day, m, k):
                return day
        return -1
            

bloom_days=[7,7,7,7,13,11,12,7]
k=3
m=2
garden=RoseGarden()
result=garden.min_days_to_make_bouquets(bloom_days,m,k)

if result==-1:
    print("We cannot make a bouquet")
else:
    print(f"Making bouquets on day {result}")