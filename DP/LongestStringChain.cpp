#include <bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2)
{
    if (s1.size() != s2.size() + 1)
        return false;
    int f = 0;
    int s = 0;
    while (f < s1.size())
    {
        if (s < s2.size() && s1[f] == s2[s])
        {
            f++;
            s++;
        }
        else
            f++;
    }
    if (f == s1.size() && s == s2.size())
        return true;
    else
        return false;
}
bool comp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
int longestChain(vector<string> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), comp); // sort by the length of each string
    for (auto i : arr)
        cout << i << ",";
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev_ind = 0; prev_ind <= i - 1; prev_ind++)
        {
            if (compare(arr[i], arr[prev_ind]) && 1 + dp[prev_ind] > dp[i])
                dp[i] = 1 + dp[prev_ind];
        }
        if (dp[i] > maxi)
            maxi = dp[i];
    }
    for (int i : dp)
        cout << i << ",";
    return maxi;
}
int main()
{
    vector<string> words = {"a", "b", "ba", "fe","bc", "bca", "bdc","feh","fehd","ccc", "bbbb", "bdca"};
    cout << longestChain(words);
}
