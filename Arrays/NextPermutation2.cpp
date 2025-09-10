#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        // find the break point where the array is not decreasing from the back of the array
        int n = nums.size();
        int ind = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            // means this is the largest permutation and the next permutation will be the smallest permutation that is the reverse of the current permutation
            reverse(nums.begin(), nums.end());
            return;
        }
        // otherwise rearrange the elements
        // find the smallest element just greater than the index element
        // the array is descending order sorted from left to right side so if we start from the back side of the array and check till the ind+1 position and swap with the first element that will be greater than ind element
        for (int i = n - 1; i > ind; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
int main(){
    vector<int>nums={1,3,2};
    Solution sol;
    sol.nextPermutation(nums);
    for(auto it:nums)
    cout<<it<<",";
}