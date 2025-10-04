#include<bits/stdc++.h>
using namespace std;
int peak(vector<int>&arr){
    // we need to handle cases of single element, case when the mid will be the first element, mid will be the last element
    int n=arr.size();
    int low=1;
    int high=n-2;
    if(n==1)return 0;// only single element
    if(arr[0]>arr[1])return 0;
    if(arr[n-1]>arr[n-2])return n-1;
    
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid-1]<arr[mid]&&arr[mid]>arr[mid+1])return mid;
        else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1])low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int main(){
    vector<int>arr={12,23,45,4,65,7,8,1,2};
    cout<<peak(arr);
}