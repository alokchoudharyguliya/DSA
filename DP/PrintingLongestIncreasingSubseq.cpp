#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubseq(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            int notTake = dp[ind + 1][prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take = 1 + dp[ind + 1][ind + 1];
            dp[ind][prev_ind + 1] = max(notTake, take);
        }
    }
    return dp[0][0];
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubseq(arr, n);
}