// Naive approach is to go for every single element and look at its vertical and horizontal neighbor that is nXm matrix takes nXmX4 time complexity

// the question states to find a single peak element that is we can return the largest element is the matrix which will be for sure a peak, this will take nXm

// but what if we want to return all the peak elements?

// we need to optimize the search space that is skip some of the array/matrix, -> Binary Search
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int maxeleind(vector<vector<int>>&arr,int mid){
        int ind=-1;
        int max_ele=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i][mid]>max_ele){
                max_ele=arr[i][mid];
                ind=i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        int low = 0;
        int high = m - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int row=maxeleind(arr,mid);

            int left=mid-1>=0?arr[row][mid-1]:INT_MIN;
            int right=mid+1?arr[row][mid+1]:INT_MIN;

            if(arr[row][mid]>left&&arr[row][mid]>right)return {row,mid};
            else if(arr[row][mid]<left)
                high=mid-1;
            else 
                low=mid+1;
        }
        return {-1,-1};
    }
};

int main()
{
    // Example usage
    vector<vector<int>> mat = {
        {1, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2}};

    // Create an instance of Solution class
    Solution sol;

    // Call findPeakGrid function and print the result
    vector<int> peak = sol.findPeakGrid(mat);
    cout << "The row of peak element is " << peak[0]
         << " and column of the peak element is " << peak[1] << endl;

    return 0;
}