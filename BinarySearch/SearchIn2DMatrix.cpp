#include<bits/stdc++.h>
using namespace std;
int bs(vector<int>&arr,int target,int low,int high){
    // int mid=(low+high)/2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]<target)low=mid+1;
        else if(arr[mid]>target)high=mid-1;
        else return mid;
    }
    return low;
}
int main(){
    vector<vector<int>>arr={{3,4,7,9},{12,13,16,18},{20,21,23,29}};
    int target=23;
    // Naive Solution takes N x M, space complexity - 1
    // But consider the property that each of the row is in itself sorted
    // we check whether the target lies between the first and last element of the current row

    // But if we consider this property that the matrix in itself is also sorted in all then we hypothetically flatten this matrix into a 1D array
    // Not storing but rather use the indexes in that way
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i][0]<=target&&arr[i][arr[0].size()-1]>=target){
        cout<<((i)*arr[0].size())+bs(arr[i],target,0,arr[i].size()-1);
        return 0;
    }
    }
    cout<<"Not Found";
}