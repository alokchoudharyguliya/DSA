#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {1, 2, 7, 5, 4, 1, 6, 3, 9};
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[small] > arr[j])
            {
                small = j;
            }
        }
        swap(arr[small], arr[i]);
    }
    for (auto i : arr)
        cout << i << ",";
}