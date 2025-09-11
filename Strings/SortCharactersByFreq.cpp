#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    static bool comparator(pair<int, int> p1, pair<int, int> p2)
    {
        if (p1.first > p2.first)
            return true; // comaprison on first element
        if (p1.first < p2.first)
            return false;
        return p1.second < p2.second;
    }

public:
    vector<char> freqSort(string &s)
    {
        pair<int, int> freq[26];
        for (int i = 0; i < 26; i++)
            freq[i] = {0, i + 'a'};
        for (char ch : s)
        {
            freq[ch - 'a'].first++; // this will map a to 0 , b->1, c->2
        }
        sort(freq, freq + 26, comparator);
        vector<char> ans;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i].first > 0)
                ans.push_back(freq[i].second);
            ;
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    string s = "tree";
    vector<char> result = sol.freqSort(s);
    for (char c : result)
        cout << c << " ";
}