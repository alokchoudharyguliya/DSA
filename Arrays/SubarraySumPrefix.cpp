#include <bits/stdc++.h>
using namespace std;
int findAllSubarrayWithGivenSum(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int,int> mpp;
    int preSum = 0, cnt = 0;
    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        preSum+=arr[i];
        int remove=preSum-k;
        cnt+=mpp[remove];
        mpp[preSum]+=1;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {3, 1, 2, 4,0,0,0};
    int k = 4;
    int cnt = findAllSubarrayWithGivenSum(arr, k);
    cout << cnt;
    return 0;
}