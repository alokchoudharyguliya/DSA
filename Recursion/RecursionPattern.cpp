#include <bits/stdc++.h>
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;
bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if (ind == n)
    {
        if (s == sum)
        {
            for (auto it : ds)
                cout << it << " ";
            return true;
            cout << endl;
        }
        else
            return false;
    }
    ds.push_back(arr[ind]);
    s+=arr[ind];
    if(printS(ind+1,ds,s,sum,arr,n)==true){
        
    }
}
int main()
{
    fio;
    int t;
    cin >> t;
    int arr[] = {1, 2, 1};
    int n = 3;

    return 0;
}