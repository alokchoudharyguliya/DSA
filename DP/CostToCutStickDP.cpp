#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int ans = cuts[j + 1] - cuts[i - 1] + findMinimumCost(i, ind - 1, cuts, dp) + findMinimumCost(ind + 1, j, cuts, dp);
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}
int minimumCost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.push_back(0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return findMinimumCost(1, c, cuts, dp);
}
int main()
{
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;
    cout << minimumCost(n, c, cuts);
}