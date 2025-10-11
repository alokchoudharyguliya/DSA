// handle the edge case of

// here we are supplying two variables to the recursive function so we will we having a 2D dp array
#include <bits/stdc++.h>
using namespace std;
// long f(long *arr, int ind, int buy, int n)
// {
//     if (ind == n)
//         return 0;
//     long a, b;
//     if (buy)
//     {
//         a = f(arr, ind + 1, buy, n);
//         b = f(arr, ind + 1, buy + 1, n) + arr[ind]; // stands for selling a stock that is a profit
//     }
//     else
//     {
//         a = f(arr, ind + 1, buy, n);
//         b = f(arr, ind + 1, buy - 1, n) - arr[ind]; // stands for buying a stock that is an investment
//     }
//     return max(a, b);
// }
// 0-> buy
// 1->sell

// MEMOIZATION APPROACH
// long getAns(long *arr, int ind, int buy, int n, vector<vector<long>> &dp)
// {
//     if (ind == n)
//         return 0;
//     if (dp[ind][buy] != -1)
//         return dp[ind][buy];
//     long profit = 0;
//     if (buy == 0)
//         profit = max(getAns(arr, ind + 1, buy, n, dp), -arr[ind] + getAns(arr, ind + 1, buy + 1, n, dp));
//     else
//         profit = max(getAns(arr, ind + 1, buy, n, dp), arr[ind] + getAns(arr, ind + 1, buy - 1, n, dp));
//     return dp[ind][buy] = profit;
// }

// TABULATION APPROACH
long getMaximumProfit(long *arr, int n)
{
    vector<vector<long>> dp(n+1, vector<long>(2, -1));
    dp[n][0] = dp[n][1] = 0; // base condition when no days are left
    if (n == 0)
        return 0;
    long profit = 0;
    // cout<<"h";
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if(buy==0) // means we can buy stock
            {
                // cout<<"e";
                profit=max(dp[ind+1][buy],-arr[ind]+dp[ind+1][buy+1]);
            }
            else{// we can sell stock
                // cout<<"y";
                profit=max(dp[ind+1][buy],arr[ind]+dp[ind+1][buy-1]);
            }
            dp[ind][buy]=profit;
        }
    }
    return dp[0][0];
}


// TABULATION APPROACH - Optimized
// long getMaximumProfit(long *arr, int n)
// {
//     // vector<vector<long>> dp(n+1, vector<long>(2, -1));
//     vector<long> a(2,0); // SPACE Optimization
//     vector<long> b(2,0); //        ,,
//     a[0] = a[1] = 0; // base condition when no days are left
//     if (n == 0)
//         return 0;
//     long profit = 0;
//     // cout<<"h";
//     for (int ind = n - 1; ind >= 0; ind--)
//     {
//         for (int buy = 0; buy <= 1; buy++)
//         {
//             if(buy==0) // means we can buy stock
//             {
//                 // cout<<"e";
//                 // profit=max(dp[ind+1][buy],-arr[ind]+dp[ind+1][buy+1]);
//                 profit=max(a[0],-arr[ind]+a[1]);
//             }
//             else{// we can sell stock
//                 // cout<<"y";
//                 // profit=max(dp[ind+1][buy],arr[ind]+dp[ind+1][buy-1]);
//                 profit=max(a[1],arr[ind]+a[0]);
//             }
//             b[buy]=profit;
//         }
//         a=b;
//     }
//     return b[0];
// }

int main()
{
    int n = 6;
    long arr[n] = {7, 1, 5, 3, 6, 4};
    cout << getMaximumProfit(arr, n);
}