#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubseq(int arr[], int n)
{
    vector<int> dp(n, 1);
    for (int i = 0; i <= n - 1; i++)
    {
        for (int prev_ind = 0; prev_ind <= i - 1; prev_ind++)
        {
            if (arr[prev_ind] < arr[i])
                dp[i] = max(dp[i], 1 + dp[prev_ind]);
        }
    }
    int ans = -1;
    for (int i = 0; i <= n - 1; i++)
        ans = max(ans, dp[i]);
    return ans;
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubseq(arr, n);
}