#include <bits/stdc++.h>
using namespace std;
vector<int> generateRow(int rowNum)
{
    long long ans = 1;
    vector<int> tempList;
    tempList.push_back(ans);
    for (int col = 1; col < rowNum; col++)
    {
        ans = ans * (rowNum - col);
        ans = ans / (col);
        tempList.push_back(ans);
    }
    // use the previously calculated values, instead of going for values again and again for each combination of row and column
    return tempList;
}

vector<vector<int>> pascalTriangle(int n)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {

        ans.push_back(generateRow(i));
    }
    return ans;
}
int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << ",";
        cout << endl;
    }
}