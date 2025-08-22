#include<bits/stdc++.h>
using namespace std;
// Naive Approach
/*
int majorityElement(vector<int>v){
	int n=v.size();
	for(int i=0;i<n;i++)
	{
	int cnt=0;
	for(int j=0;j<n;j++)
	{
		if(v[j]==v[i])
			cnt++;
	}
	if(cnt>(n/2))
		return v[i];
	}
}
*/
// Hashmap Approach
/*
int majorityElement(vector<int>v){
	int n=v.size();
	map<int,int>omap;
	for(int i=0;i<n;i++)
	omap[arr[i]]++;
	for(auto it:omap)
	if(it.second>(n/2))
		return it.first;
		return -1;
}
 */
// Moore's Voting Algorithm

int majorityElement(vector<int>v){

	int n=v.size();
	int cnt=0;
	int el;
	for(int i=0;i<n;i++)
	{
	if(cnt==0){
	cnt=1;
	el=v[i];
	}
	else if (el==v[i])
	cnt++;
	else
	cnt--;
	}

	int cnt1=0;
	for(int i=0;i<n;i++)
	if(v[i]==el)cnt1++;

	if(cnt1>(n/2)) return el;
	return -1;
	}


int main(){
	vector<int>arr={2,2,1,1,1,2,2};
	int ans=majorityElement(arr);
	cout<<ans<<endl;
	return 0;
}
