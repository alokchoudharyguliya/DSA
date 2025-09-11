#include <bits/stdc++.h>
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;
void pV(vector<int> arr)
{
    for (auto i : arr)
        cout << i << " ";
    cout << endl;
}
int main()
{
    fio;
    // int t;
    // cin >> t;
    // while (t--)
    // {

    // }
    int n = 3;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    int subsets = 1 << n;
    for (int num = 0; num < subsets; num++)
    {
        vector<int> lists;
        for (int i = 0; i <= n - 1; i++)
        {
            (num & (1 << i)) ? (void)(lists.push_back(nums[i])) : (void)0;
        }
        ans.push_back(lists);
    }
    for (auto it : ans)
        pV(it);
    return 0;
}

// TC -> N*2^n