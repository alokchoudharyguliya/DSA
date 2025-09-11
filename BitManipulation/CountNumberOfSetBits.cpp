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
    int t;
    cin >> t;
    int cnt = 0;
    //==============================
    // while (t > 1)
    // {
    //     if (t % 2 == 1)
    //         cnt++;
    //     t /= 2;
    // }
    // if (t == 1)
    //     cnt += 1;
    //==============================
    // while (t > 1)
    // {
    //     cnt += t & 1;
    //     t >>= 1;
    // }
    // if (t == 1)
    //     cnt += 1;
    // cout << cnt << "\n";
    //==============================
    while (t > 0)
    {
        t &= t - 1;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}