#include<bits/stdc++.h>
using namespace std;
void bubble(vector<int>&arr,int n){
    if(n==1)return;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
    }
    bubble(arr,n-1);
    return;
}
int main(){
    vector<int>arr={6,2,4,7,3,9,11,2,1};
    bubble(arr,arr.size());
    for(int j:arr)
    cout<<j<<",";
}