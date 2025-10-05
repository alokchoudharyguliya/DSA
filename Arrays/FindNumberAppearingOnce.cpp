#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int>&arr){
    int ans=arr[0];
    for(int i=1;i<arr.size();i++)
    ans=ans^arr[i];
    return ans;
}
int main(){
    vector<int>arr={4,1,2,1,2}    ;
    int ans=getSingleElement(arr);
    cout<<ans;
}