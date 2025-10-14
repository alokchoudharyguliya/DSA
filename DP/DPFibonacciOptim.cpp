// Space optimized DP for Fibonacci
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int prev2 = 0;
    int prev1 = 1;
    int ans = 0;
    for (int i = 2; i <= 5; i++)
    {
        ans = prev2 + prev1;
        prev2 = prev1;
        prev1 = ans;
    }
    cout << prev1;
}