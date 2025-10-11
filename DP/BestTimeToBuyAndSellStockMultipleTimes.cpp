// handle the edge case of

#include <bits/stdc++.h>
using namespace std;
long f(long *arr, int ind, int buy, int n)
{
    if (ind == n)
        return 0;
    long a, b;
    if (buy)
    {
        a = f(arr, ind + 1, buy, n);
        b = f(arr, ind + 1, buy + 1, n) + arr[ind]; // stands for selling a stock that is a profit
    }
    else
    {
        a = f(arr, ind + 1, buy, n);
        b = f(arr, ind + 1, buy - 1, n) - arr[ind]; // stands for buying a stock that is an investment
    }
    return max(a, b);
}

long getMaximumProfit(long *arr, int n)
{
    return f(arr, 0, 0, n);
}

int main()
{
    int n = 6;
    long arr[n] = {7, 1, 5, 3, 6, 4};
    cout << getMaximumProfit(arr, n);
}