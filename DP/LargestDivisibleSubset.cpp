#include<bits/stdc++.h>
using namespace std;
vector<int>divisibleSet(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    vector<int>dp(n,1);
    vector<int>hash(n,1);
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev_ind=0;prev_ind<i;prev_ind++){
            if(arr[i]%arr[prev_ind]==0&&1+dp[prev_ind]>dp[i])
            {
                dp[i]=1+dp[prev_ind];
                hash[i]=prev_ind;
            }
        }
    }
    int ans=-1;
    int lastIndex=-1;
    for(int i=0;i<n;i++){
        if(dp[i]>ans){
            ans=dp[i];
            lastIndex=i;
        }
    }
    vector<int>temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex]!=lastIndex)
    {
        lastIndex=hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
int main(){
    vector<int>arr={1,16,7,8,4};
    vector<int>ans=divisibleSet(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
}