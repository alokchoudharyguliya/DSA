#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 6, 7, 4, 3, 6, 5};
    stack<int> s;
    vector<int> res(arr.size(),-1);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        while (!s.empty()&&s.top() < arr[i] )
        {
            s.pop();
        }
        if (s.empty())
            res[i] = -1;
        else
            res[i] = s.top();
        s.push(arr[i]);
    }
    for (auto i : res)
        cout << i << ",";
}