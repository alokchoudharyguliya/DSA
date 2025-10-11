#include <bits/stdc++.h>
using namespace std;
// this question asks for remembering the price which was lowest till now so comes under dp over a single variable
int maximumProfit(vector<int> &arr)
{
    int maxProfit = 0;
    int mini = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        int curProfit = arr[i] - mini;
        maxProfit = max(maxProfit, curProfit);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maximumProfit(arr);
}