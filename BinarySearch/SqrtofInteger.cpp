#include<bits/stdc++.h>
using namespace std;
int main(){
    int num;
    cin>>num;
    int low=1;
    int high=num;
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid>num){
            high=mid-1;
        }
        else
        {
            ans=low;
            low=mid+1;
        }
    }
    cout<<ans;
}