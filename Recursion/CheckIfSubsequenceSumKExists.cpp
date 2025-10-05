#include<bits/stdc++.h>
using namespace std;
bool helper(vector<int>arr,int sum, int ind){
    if(sum==0){
        return true;
    }
    if(ind==arr.size()||sum<0)return false;
    return helper(arr,sum,ind+1)||helper(arr,sum-arr[ind],ind+1);
}
bool solve(vector<int>&arr,int k){
    return helper(arr,k,0);
}
int main(){
    int k=55;
    vector<int>arr={4,9,5,2,1};
    cout<<solve(arr,k);
}