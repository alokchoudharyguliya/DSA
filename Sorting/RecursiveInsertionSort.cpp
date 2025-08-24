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
void insertion(vector<int>&arr,int n,int i){
    if(i==n)return;
    int temp=i;
    int var=arr[i];
    while(i>0&&arr[i]<arr[i-1]){
            swap(arr[i-1],arr[i]);
            i--;
    }
    arr[i]=var;
    insertion(arr,n,temp+1);
    return;
}
int main()
{
    fio;
    int t;vector<int>arr={6,2,4,7,3,9,11,2,1};
    insertion(arr,arr.size(),1);
for (auto it : arr)
		cout << it << ",";
	cout << endl;
return 0;
}