#include <bits/stdc++.h>
using namespace std;
int searchele(vector<int> &arr, int tar)
{
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == tar)
            return mid;
        if (arr[mid] <= arr[high])
        {
            // means second half is sorted
            if (arr[mid] <= tar && arr[high] >= tar)
            {
                // search in second half
                low = mid + 1;
            }
            else
            {
                // search in first half
                high = mid - 1;
            }
        }
        else
        {
            // means first half is sorted
            if (arr[mid] >= tar && arr[low] <= tar)
            {
                // search in second half
                low = mid + 1;
            }
            else
            {
                // search in first half
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> arr = {5, 6, 1, 2, 3, 4};
    cout << searchele(arr, 3);
}