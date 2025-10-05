#include <bits/stdc++.h>
#define fio                   \
ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
using ll=long long;
using ld=long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;
// here in this approach we simply use the concept that the sum of numbers starting from 1 to N will be N*(N+1)/2;
// so we simply find the current array sum and subtract that from the N*(N+1)/2 sum 
int missingNumber(vector<int>&arr,int n){
    int sum=(n*(n+1))>>1;
    int accum=0;
    for(int i=0;i<arr.size();i++)
    accum+=arr[i];
    return sum-accum;
}
int main()
{
    fio;
    int n=5;
    vector<int>arr={1,2,4,5};
    cout<<missingNumber(arr,n);
    return 0;
}