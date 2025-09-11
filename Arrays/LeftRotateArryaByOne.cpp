#include <bits/stdc++.h>
using namespace std;
void leftRotate(vector<int> &arr)
{
    int temp = arr[0];
    for (int i = 0; i < arr.size() - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[arr.size() - 1] = temp;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    leftRotate(arr);
    for (int x : arr)
        cout << x << ",";
}