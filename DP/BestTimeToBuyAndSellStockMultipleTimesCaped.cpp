#include <bits/stdc++.h>
using namespace std;
// int helper(vector<int> &prices, int n, int cap, int ind, int buy)
// {
//     if (cap == 0 || ind == n)
//         return 0;

//     int o = 0;
//     int p = 0;
//     if (buy == 0)
//     {
//         o = helper(prices, n, cap, ind + 1, buy);                    // did nothing
//         p = -prices[ind] + helper(prices, n, cap, ind + 1, buy + 1); // sold
//     }
//     if (buy == 1)
//     {
//         o = helper(prices, n, cap, ind + 1, buy);                       // did nothing
//         p = prices[ind] + helper(prices, n, cap - 1, ind + 1, buy - 1); // sold
//     }
//     return max(o, p);
// }

// here requiring 3 variables to be passed in recurrence function therefore a 3D array
// int getAns(vector<int> &prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>> &dp)
// {
//     if (ind == n || cap == 0)
//         return 0;

//     if (dp[ind][buy][cap] != -1)
//         return dp[ind][buy][cap];
//     int profit;
//     if (buy == 0)
//     {
//         profit = max(getAns(prices, n, ind + 1, buy, cap, dp), -prices[ind] + getAns(prices, n, ind + 1, buy + 1, cap, dp));
//     }
//     if (buy != 0)
//     {
//         profit = max(getAns(prices, n, ind + 1, buy, cap, dp), prices[ind] + getAns(prices, n, ind + 1, buy - 1, cap - 1, dp));
//     }
//     return dp[ind][buy][cap]=profit;
// }
// TABULATION APPROACH - as in previous Memoization approach, here we will create a 3D table that is dp[n+1][2][3]

int getAnsTabulation(vector<int> &prices, int n, int ind, int buy, int cap, vector<vector<vector<int>>> &dp)
{
    // setting up the base conditions
    // first is when ind=0
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            dp[0][buy][cap] = 0;
        }
    }

}

// int maxProfit(vector<int> &prices, int n)
// {
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
//     return getAns(prices, n, 0, 0, 2, dp);
// }
// int maxProfit(vector<int> &prices, int n)
// {
//     return helper(prices, n, 2, 0, 0);
// }

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    cout << maxProfit(prices, n);
}