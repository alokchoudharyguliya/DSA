#include<bits/stdc++.h>
using namespace std;
// bool subsetSumToK(int n,int k,vector<int>&arr){
//     // 
//     if(k==0)return true;
//     if(n==0)return arr[0]==k;
//     return subsetSumToK(n-1,k-arr[n],arr)||subsetSumToK(n-1,k,arr);

// }
bool subsetSumToK(int n, int k, vector<int>&arr,vector<vector<int>>&dp){
    if(n==0)return arr[0]==k;
    if(k==0)return true;
    if(dp[n][k]==-1){
        if(k>=arr[n])
        dp[n][k]=subsetSumToK(n-1,k,arr,dp)||subsetSumToK(n-1,k-arr[n],arr,dp);
        else
        dp[n][k]=false;
    }
    return dp[n][k];
}
int main(){
    vector<int>arr={1,2,2,4};
    int k=4;
    int n=arr.size()-1;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    if(subsetSumToK(n,k,arr,dp)){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}