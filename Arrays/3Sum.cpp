#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> triplet(int n, vector<int> &arr)
{
	set<vector<int>> st;// we want unique triplet combinations
	for (int i = 0; i < n; i++)
	{
		set<int>thirdElementHashSet;
		for (int j = i + 1; j < n; j++)
		{
			int third=-(arr[i]+arr[j]);
			if (thirdElementHashSet.find(third)!=thirdElementHashSet.end())
			{
				vector<int>temp={arr[i],arr[j],third};
				sort(temp.begin(),temp.end());
				st.insert(temp);
			}
			thirdElementHashSet.insert(arr[j]);// insert each of the element between i and j
		}
	}
	vector<vector<int>>ans(st.begin(),st.end());
	return ans;
}
int main()
{

	vector<int> arr = {-1, 0, 1, 2, -1, -4};
	int n = arr.size();
	vector<vector<int>> ans = triplet(n, arr);
	for (auto it : ans)
	{
		cout << "[";
		for (auto i : it)
			cout << i << ",";
		cout << "]";
	}
	cout << endl;
	return 0;
}
