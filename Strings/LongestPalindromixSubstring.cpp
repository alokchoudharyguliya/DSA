#include <bits/stdc++.h>
using namespace std;
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

int main()
{
    fio;
    string s;
    cin >> s;
    string maxStr = "";
    for (int i = 0; i < s.length(); i++)
    {
        int l = i, r = i;
        while (l >= 0 && r < s.length())
        {
            if (s[l] == s[r])
            {
                if (r - l + 1 > maxStr.length())
                {
                    maxStr = s.substr(l, r - l + 1);
                }
                r++;
                l--;
                continue;
            }
            break;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < s.length())
        {
            if (s[l] == s[r])
            {
                if (r - l + 1 < maxStr.length())
                {
                    maxStr = s.substr(l, r - l + 1);
                }
                r++;
                l--;
                continue;
            }
            break;
        }
    }
    cout << maxStr;
}
