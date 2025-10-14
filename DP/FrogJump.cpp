// #include<bits/stdc++.h>
// using namespace std;
// int fun(vector<int>&arr,int n){
//     if(n<=1)return 0;
//     return abs(arr[n]-arr[n-1])+fun(arr,n-1);
// }
// int main(){
//     int n=4;
//     vector<int>arr={10,20,30,10};
//     cout<<fun(arr,n-1);

// }

#include <bits/stdc++.h>
using namespace std;
int fun(vector<int> &arr, int n, vector<int> &dp)
{
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int right=INT_MAX;
    int left=abs(arr[n] - arr[n - 1]) + fun(arr, n - 1, dp);
    if(n>1)
    right=abs(arr[n] - arr[n - 2]) + fun(arr, n - 2, dp);
    return dp[n] = min(right,left);
}
int main()
{
    int n = 4;
    vector<int> dp(n + 1, -1);
    vector<int> arr = {10, 20, 30, 10};
    cout << fun(arr, n - 1, dp);
}


// #include <bits/stdc++.h>
// using namespace std;
// int fun(vector<int> &arr, int n, vector<int> &dp)
// {
//     if (n <= 0)
//         return 0;
//     if (dp[n] != -1)
//         return dp[n];
//     return dp[n] = min(abs(arr[n] - arr[n - 1]) + fun(arr, n - 1, dp),abs(arr[n] - arr[n - 2]) + fun(arr, n - 2, dp));
// }
// int main()
// {
//     int n = 4;
//     vector<int> dp(n + 1, -1);
//     vector<int> arr = {10, 20, 30, 10};
//     cout << fun(arr, n - 1, dp);
// }

