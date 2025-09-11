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
void helper(vector<int>&arr,int ind,vector<int>&temp,int sum){
    if(ind==arr.size()){
        temp.push_back(sum);
        return;
    }
    helper(arr,ind+1,temp,sum+arr[ind]);
    while(ind+1<arr.size()&&arr[ind]==arr[ind+1])ind++;
    helper(arr,ind+1,temp,sum);
}
vector<int>fun(vector<int>arr){
    vector<int>temp;
    sort(arr.begin(),arr.end());
    helper(arr,0,temp,0);
    return temp;
}
int main()
{
    fio;
    // int t;
    // cin >> t;
    // while (t--)
    // {
        
    // }
    vector<int>arr={3,1,2,3};
    vector<int>res=fun(arr);
    for(auto it:res)cout<<it<<" ";
return 0;
}