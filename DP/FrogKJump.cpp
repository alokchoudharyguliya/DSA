#include <bits/stdc++.h>
using namespace std;
int f(vector<int>&arr,int n,int k){
    if(n<=0)return 0;
    // int right=INT_MAX;
    // int left=f(arr,n-1)+abs(arr[i]-arr[i-1]);
    // if(i>1)
    //     right=f(arr,n-2)+abs(arr[i]-arr[i-2]);
    int left,ans;
    for(int diff=1;diff<=k;diff++){
        left=f(arr,n-diff,k)+abs(arr[n]-arr[n-diff]);
        ans=min(left,ans);
    }
    return ans;
}

int main()
{
    int n = 4;
    vector<int> arr = {10, 20, 30, 10};
    int k=2;
    cout << f(arr, n - 1,k);
}
