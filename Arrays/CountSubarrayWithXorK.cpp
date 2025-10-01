#include<bits/stdc++.h>
using namespace std;
// int subarrayWithXorK(vector<int>a,int k){
//     int n=a.size();
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int xorr=0;
//             for(int l=i;l<=j;l++)xorr=xorr^a[l];
//             if(xorr==k)cnt++;
//         }
//     }
//     return cnt;
// }

// Better
// int subarrayWithXorK(vector<int>a,int k){
//     int n=a.size();
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         int xorr=0;
//         for(int j=i;j<n;j++){
//             xorr=xorr^a[j];
//             if(xorr==k)cnt++;
//         }
//     }
//     return cnt;
// }

// Optimal
// Using Prefix XOR
int subarrayWithXorK(vector<int>a,int k){
    int n=a.size();
    int xr=0;
    map<int,int>mp;
    mp[xr]++;
    int cnt=0;
    for(int i=0;i<n;i++){
        xr=xr^a[i];

        int x=xr^k;
        cnt+=mp[x];
        mp[xr]++;
    }
    return cnt;
}
int main(){
    vector<int>a={4,2,2,6,4};
    int k=6;
    cout<<subarrayWithXorK(a,k);
}