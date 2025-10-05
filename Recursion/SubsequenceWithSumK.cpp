#include <bits/stdc++.h>
using namespace std;
int helper(vector<int> &arr, int sum, int ind)
{   
    // the order of checking the base conditions matters as for a array where we obtain the sum after using the last value we won't be able to count that as at last ind==arr.size() will become true and will return 0
    if (sum == 0)
    {
        return 1;
    }
    if (ind == arr.size() || sum < 0)
    {
        return 0;
    }
    return helper(arr, sum - arr[ind], ind + 1) + helper(arr, sum, ind + 1);
}
int solve(vector<int> &arr, int k)
{
    return helper(arr, k, 0);
}
int main()
{
    int k = 10;
    vector<int> arr = {4, 9, 2, 5, 1};
    cout << solve(arr, k);
}