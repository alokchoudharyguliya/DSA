def return_subsequences(s1):
    if(s1==""):
        ans=[""]
        return ans
    sub_ans=return_subsequences(s1[1:])
    ans=[]
    ans.extend(sub_ans)
    for i in sub_ans:
        ans.append(s1[0]+i)
    return ans


s1="abcd"
l1=return_subsequences(s1)

print(l1)