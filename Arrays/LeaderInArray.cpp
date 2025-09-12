#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFORR(i, a, b) for (int i = (a); i >= (b); i--)
int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> ans;
    int max_ele = arr[arr.size() - 1];
    ans.push_back(max_ele);
    RFORR(i, arr.size() - 2, 0)
    {
        if (arr[i] > max_ele)
        {
            max_ele = arr[i];
            ans.push_back(arr[i]);
        }
        // else
        // {
        // }
    }
    // for(auto it:ans)
    RFORR(i,ans.size()-1,0)
    cout<<ans[i]<<",";
}