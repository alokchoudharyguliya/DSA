#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    void fun(vector<int> &candidates, int index, int target, vector<int> &path)
    {
        if (target == 0)
        {
            ans.push_back(path);
        }
        if (target - candidates[index] >= 0)
        {
            path.push_back(candidates[index]);
            fun(candidates, index, target - candidates[index], path);
        }
        path.pop_back();
        fun(candidates, index + 1, target, path);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        // either consider this element or don't
        // stop when either the array gets empty means we couldn't reach or the target becomes 0 means we reached our target
        vector<int> path;
        fun(candidates, 0, target, path);
        return ans;
    }
};
int main()
{
    vector<int> candidates = { 2, 3, 6, 7};
    int target = 7;
    Solution sol;
    vector<vector<int>> ans = sol.combinationSum(candidates, target);
    for (auto i : ans)
    {
        for (auto it : i)
            cout << it << ",";
        cout << ";";
    }
}