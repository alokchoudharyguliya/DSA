#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubseq(int arr[], int n)
{
    vector<int> next(n + 1, 0);
    vector<int> cur(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >=- 1; prev_ind--)
        {
            int notTake = next[prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take = 1 + next[ind + 1];
            cur[prev_ind + 1] = max(notTake, take);
        }
        next = cur;
    }
    return cur[0];
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubseq(arr, n);
}#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubseq(int arr[], int n)
{
    vector<int> next(n + 1, 0);
    vector<int> cur(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >=- 1; prev_ind--)
        {
            int notTake = next[prev_ind + 1];
            int take = 0;
            if (prev_ind == -1 || arr[ind] > arr[prev_ind])
                take = 1 + next[ind + 1];
            cur[prev_ind + 1] = max(notTake, take);
        }
        next = cur;
    }
    return cur[0];
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubseq(arr, n);
}