#include <bits/stdc++.h>
using namespace std;
int findMinimum(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;
    int mini = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int ans = cuts[j + 1] - cuts[i - 1] + findMinimum(i, ind - 1, cuts) + findMinimum(ind + 1, j, cuts);
        mini = min(ans, mini);
    }
    return mini;
}
int minimumCost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.push_back(0);
    // cuts.insert(cuts.begin(),0);
    sort(cuts.begin(), cuts.end());
    return findMinimum(1, c, cuts);
}
int main()
{
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;
    cout << minimumCost(n, c, cuts);
}