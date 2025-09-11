#include <bits/stdc++.h>
using namespace std;
void RotateLeft(int arr[], int n, int k)
{
    k = k % n;
    // vector<int>temp(k);
    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i = 0; i < n - k; i++)
    {
        arr[i] = arr[i + k];
    }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - n + k];
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