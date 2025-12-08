#include <bits/stdc++.h>
using namespace std;
int atMostKDistinct(string s, int k)
{
    int left = 0, res = 0;
    unordered_map<char, int> freq; // map for character frequency
    for (int right = 0; right < s.size(); right++)
    {
        freq[s[right]]++;// freq of right character
        while (freq.size() > k) // shrink window if distinct character exceed k
        {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
                freq.erase(s[left]);
            left++;
        }
        // count substrings in current window
        res += (right - left + 1);
    }
    return res;
}
// function to count substrings with exactly k distinct characters
int countSubstrings(string s, int k)
{
    // exactly k = atMost(k)-atMost(k-1);
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}
int main()
{
    string s = "pqpqs";
    int k = 2;
    cout << countSubstrings(s, k) << endl;
    return 0;
}