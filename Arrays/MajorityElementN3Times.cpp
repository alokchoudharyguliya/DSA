/*
 * Given an array of N integers, Find the element that appear more than N/3 times in the array. If no such element exists, return an empty vector
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
/*
vector<int>majorityElement(vector<int>v){
	int n=v.size();
	vector<int>ls;

	for(int i=0;i<n;i++){
		if(ls.size()==0||ls[0]!=v[i]){
			int cnt=0;
			for(int j=0;j<n;j++){
				if(v[j]==v[i])
					cnt++;

			}
			if(cnt>(n/3))
				ls.push_back(v[i]);

		}
		if(ls.size()==2) break;
	}
	return ls;
}
*/
/*
vector<int>majorityElement(vector<int>v){
	int n=v.size();
	vector<int>ls;

	map<int,int>mpp;
	int mini=int(n/3)+1;
	for(int i=0;i<n;i++){
		mpp[v[i]]++;
		if(mpp[v[i]]==mini){
			ls.push_back(v[i]);
		}
		if(ls.size()==2)break;
	}
	return ls;

}
*/

// Extended Boyer Moore's Voting Algorithm
// cnt1 & cnt2 -> Tracking the counts of elements
//  el1 & el2 -> for storing the majority of elements

vector<int> majorityElement(vector<int> &arr)
{
	int ele1 = INT_MIN, ele2 = INT_MIN, cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		if (cnt1 == 0 && arr[i] != ele2)
		{
			cnt1 = 1;
			ele1 = arr[i];
		}
		else if (cnt2 == 0 && arr[i] != ele1)
		{
			cnt2 = 1;
			ele2 = arr[i];
		}
		else if (arr[i] == ele1)
			cnt1++;
		else if (arr[i] == ele2)
			cnt2++;
		else
		{
			cnt1--, cnt2--;
		}
	}
	return vector<int>{ele1, ele2};
}

int main()
{
	vector<int> arr = {11, 33, 3, 11, 33, 1};
	vector<int> ans = majorityElement(arr);
	cout << "Majority Element are: ";
	for (auto it : ans)
		cout << it << ",";
	cout << endl;
	return 0;
}
