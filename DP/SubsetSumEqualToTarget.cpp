#include<bits/stdc++.h>
using namespace std;
// bool subsetSumToK(int n,int k,vector<int>&arr){
//     // 
//     if(k==0)return true;
//     if(n==0)return arr[0]==k;
//     return subsetSumToK(n-1,k-arr[n],arr)||subsetSumToK(n-1,k,arr);
// }
// bool subsetSumToK(int n, int k, vector<int>&arr,vector<vector<int>>&dp){
//     if(k==0)return true;
//     if(n==0)return arr[0]==k;
//     if(dp[n][k]==-1){
//         bool nottaken=subsetSumToK(n-1,k,arr,dp);
//         if(k>=arr[n])
//         dp[n][k]=nottaken||subsetSumToK(n-1,k-arr[n],arr,dp);
//         else
//         dp[n][k]=nottaken;
//     }
//     return dp[n][k];
// }
int main(){
    vector<int>arr={1,1,1,1,40};
    int k=4;
    int n=arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    for(int i=0;i<n;i++)
        dp[i][0]=true;
    if(arr[0]<=k)
        dp[0][arr[0]]=true;
    for(int sum=1;sum<=k;sum++){
        for(int i=1;i<n;i++){
            if(sum>=k)
            dp[i][sum]=dp[i][sum-k]||dp[][];
        }
    }
    // if(subsetSumToK(n-1,k,arr,dp)){
    //     cout<<"True"<<endl;
    // }
    // else{
    //     cout<<"False"<<endl;
    // }
}