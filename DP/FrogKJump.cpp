#include <bits/stdc++.h>
using namespace std;
// int f(vector<int>&arr,int n,int k,vector<int>&dp){
//     if(n==0)return 0;
//     // int right=INT_MAX;
//     // int left=f(arr,n-1)+abs(arr[i]-arr[i-1]);
//     // if(i>1)
//     //     right=f(arr,n-2)+abs(arr[i]-arr[i-2]);
//     int left=0,ans=INT_MAX;
//     if(dp[n]!=-1)return dp[n];
//     for(int diff=1;diff<=k;diff++){
//         if(n-diff>=0)
//         left=f(arr,n-diff,k,dp)+abs(arr[n]-arr[n-diff]);
//         ans=min(left,ans);
//     }
//     return dp[n]=ans;
// }

int f(vector<int> &arr, int n, int k, vector<int> &dp)
{
    dp[0] = 0; // if(n==0)return 0;
    // int right=INT_MAX;
    // int left=f(arr,n-1)+abs(arr[i]-arr[i-1]);
    // if(i>1)
    //     right=f(arr,n-2)+abs(arr[i]-arr[i-2]);
    // if(dp[n]!=-1)return dp[n];
    for (int i = 1; i <= n; i++)
    {
        int left = 0, ans = INT_MAX;
        for (int diff = 1; diff <= k; diff++)
        {
            if (i - diff >= 0)
                left = dp[i - diff] + abs(arr[i] - arr[i - diff]);
            ans = min(left, ans);
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main()
{
    int n = 4;
    vector<int> arr = {10, 20, 30, 10};
    vector<int> dp(n, -1);
    int k = 2;
    cout << f(arr, n - 1, k, dp);
}
