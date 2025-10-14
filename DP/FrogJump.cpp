#include<bits/stdc++.h>
using namespace std;
int fun(vector<int>&arr,int n,vector<int>&dp){
    if(n<=1)return 0;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=abs(arr[n]-arr[n-1])+fun(arr,n-1,dp);
}
int main(){
    int n=4;
    vector<int>dp(n+1,-1);
    vector<int>arr={10,20,30,10};
    cout<<fun(arr,n-1,dp);

}