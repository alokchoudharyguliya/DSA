#include <bits/stdc++.h>
using namespace std;    
int helper(int arr[],int prev_ind, int ind,int n){
    if(ind==n)return 0;

    int nottake=helper(arr,prev_ind,ind+1,n);
    int take=0;
    if(prev_ind==-1||arr[prev_ind]<arr[ind])
        take=1+helper(arr,ind,ind+1,n);
    return max(take,nottake);
}   
int longestIncreasingSubseq(int arr[], int n)
{
    return helper(arr,-1,0,n);
}
int main()
{
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longestIncreasingSubseq(arr, n);
}