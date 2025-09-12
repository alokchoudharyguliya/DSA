#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
int stockSum(vector<int> &arr)
{
    int minn = INT_MAX;
    int sum = INT_MIN;
    FOR(i, 0, arr.size())
    {
        minn = min(minn, arr[i]);
        sum = max(sum, arr[i] - minn);
    }
    return sum;
}
int main()
{
    vector<int> arr = {2, 1, 3, 14, 1, 2, 1, 5, 4};
    cout << stockSum(arr);
}