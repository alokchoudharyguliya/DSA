#include <bits/stdc++.h>
using namespace std;
// int fun(vector<int> &arr, int n, vector<int> &dp)
// {
//     dp[0] = 0; // if (n == 0)
//     //     return 0;
//     for (int i = 1; i <= n; i++)
//     {
//         int right = INT_MAX;
//         int left = abs(arr[i] - arr[i - 1]) + dp[i - 1];
//         if (i > 1)
//             right = abs(arr[i] - arr[i - 2]) + dp[i - 2];
//         dp[i] = min(right, left);
//     }
//     return dp[n];
// }

int fun(vector<int> &arr, int n, vector<int> &dp)
{
    int p1=0,p2=0;// dp[0] = 0; // if (n == 0)
    //     return 0;
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        int right = INT_MAX;
        int left = abs(arr[i] - arr[i - 1]) + p1;
        if (i > 1)
            right = abs(arr[i] - arr[i - 2]) + p2;
        ans = min(right, left);
        p2=p1,p1=ans;
    }
    return p1;
}

int main()
{
    int n = 4;
    vector<int> dp(n + 1, -1);
    vector<int> arr = {10, 20, 30, 10};
    cout << fun(arr, n - 1, dp);
}
