s1="abc"

def return_permutation(s1):
    if(s1==""):
        return [""]
    
    allPermutation=[]
    for i in return_permutation(s1[1:]):
        for pos in range(0,len(i)+1):
            allPermutation.append(i[0:pos]+s1[0]+i[pos:])
    return allPermutation

print(return_permutation(s1))