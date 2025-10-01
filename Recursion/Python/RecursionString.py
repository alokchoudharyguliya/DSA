# remove character
def remove_char(s1,ch):
    if(len(s1)==0 or s1==""):
        return s1
    ans=remove_char(s1[1:],ch)
    if(s1[0]==ch):
        return ans # skip the current character
    else:
        return s1[0]+ans


s1="abczz"
ans=remove_char(s1,"z")
print(ans)