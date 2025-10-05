// generate all the binary strings of length which doesn't have any consecutive ones

#include<bits/stdc++.h>
using namespace std;
void solve(string curr,int ind,int n,vector<string>&ans){
    if(ind==n){
        ans.push_back(curr);
        return;
    }
    solve(curr+"0",ind+1,n,ans);
    if(curr.empty()||curr[ind-1]!='1') // if empty string then allow, or if previous character not 1 then allow curr.back()!='1'
    solve(curr+"1",ind+1,n,ans);
}
vector<string>generateBin(int n){
    vector<string>ans;
    solve("",0,n,ans);
    return ans;
}

int main(){
    int n=3;
    vector<string>res=generateBin(n);
    for(string s:res)cout<<s<<",";
}