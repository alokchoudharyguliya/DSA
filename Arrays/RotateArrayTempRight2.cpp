#include <bits/stdc++.h>
using namespace std;
void RotateRight(int arr[], int n, int k)
{
    if (!n)
        return;
    k = k % n;
    vector<int> temp;
    for (int i = n - k; i < n; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}
int main()
{
    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 12;
    RotateLeft(arr, n, k);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}