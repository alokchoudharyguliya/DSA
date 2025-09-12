#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
vector<int> maxSum(vector<int> &arr)
{
    int sum = 0;
    int maxi = INT_MIN;
    int ansStart = -1, ansEnd = -1;
    int start = 0;
    FOR(i, 0, arr.size())
    {
        (sum == 0) ? start = i : (int)0;
        sum += arr[i];
        (sum > maxi) ? (ansStart = start, ansEnd = i, maxi = sum) : (int)0;
        (sum < 0) ? sum = 0 : (int)0;
    }
    return {ansStart,ansEnd};
}
int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> ans = maxSum(arr);
    FOR(i, 0, ans.size())
    cout << ans[i] << ",";
}