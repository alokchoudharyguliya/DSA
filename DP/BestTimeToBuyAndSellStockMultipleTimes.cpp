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
long getAns(long *arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    long profit = 0;
    if (buy == 0)
        profit = max(getAns(arr, ind + 1, buy, n, dp), -arr[ind] + getAns(arr, ind + 1, buy + 1, n, dp));
    else
        profit = max(getAns(arr, ind + 1, buy, n, dp), arr[ind] + getAns(arr, ind + 1, buy - 1, n, dp));
    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *arr, int n)
{
    vector<vector<long>> dp(n, vector<long>(2, -1));
    if (n == 0)
        return 0;
    return getAns(arr, 0, 0, n, dp);
}

int main()
{
    int n = 6;
    long arr[n] = {7, 1, 5, 3, 6, 4};
    cout << getMaximumProfit(arr, n);
}