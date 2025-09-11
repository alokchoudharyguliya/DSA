#include <bits/stdc++.h>
using namespace std;
void RotateLeft(int arr[], int n, int k)
{
    if (n == 0)
        return;
    k = k % n;
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);
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