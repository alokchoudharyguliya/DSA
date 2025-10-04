// Floor - largest element smaller than or equal to x
// ceil - smallest element greater than or equal to x
// n=6, arr[]={3,4,4,7,8,10}, x=5
// ceil is 7, floor is 4

// What is the floor of x?
// The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).

// What is the ceiling of x?
// The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).

#include<bits/stdc++.h>
using namespace std;
pair<int,int>solve(vector<int>&arr,int tar){
    int low=0;
    int high=arr.size()-1;
    int floor=-1,ceil=-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid]<=tar){
            floor=arr[mid];
        low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    low=0,high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid]>=tar){
            ceil=arr[mid];
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return make_pair(ceil,floor);
}

int main(){
    vector<int>arr={3,4,4,7,8,10};
    pair<int,int>ans=solve(arr,5);
    cout<<ans.first<<","<<ans.second<<endl;
}