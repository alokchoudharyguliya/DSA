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
int main()
{
    fio;
    vector<int> arr = {4, 1, 1, 2, 3, 6};
    // find the xor of the range array
    int a = arr[0];
    for (int i = 1; i < arr.size(); i++)
        a = a ^ (i + 1);
    // 100 is the differentiating bit that is the third bit is the differentiating bit
    // take the bitwise &
    vector<int> ev;
    vector<int> od;
    int size = arr.size();
    for (int i = 1; i <= size; i++)
        arr.push_back(i);
    for (int i = 0; i < arr.size(); i++)
    {
        int b = (arr[i] & 1<<a);
        // if (arr[i] == 5)
        // {
        //     cout << b;
        //     cout << a;
        // }
        int ref=1<<a;
        // cout<<b<<","<<ref;
        if (b == ref)
            ev.push_back(arr[i]);
        else
            od.push_back(arr[i]);
    }
    int ansA = 0;
    for (auto i : ev)
        ansA = ansA ^ i;

    int ansB =0;
    for (auto i : od)
        ansB = ansB ^ i;

    // cout << "\n";
    // for (auto i : od)
    //     cout << i;
    // cout << "\n";
    // for (auto i : ev)
    //     cout << i;
    cout << ansA << "," << ansB;
    return 0;
}