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
int findAllSubarrayWithGivenSum(vector<int> arr, int k)
{
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    fio;
    // int t;
    // cin >> t;
    // while (t--)
    // {

    // }
    int n = 4;
    vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = findAllSubarrayWithGivenSum(arr, k);
    cout << cnt << "\n";
    return 0;
}