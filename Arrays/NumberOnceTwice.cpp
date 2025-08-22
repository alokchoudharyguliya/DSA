/*
 * Non-empty array of integers arr, every element appears twice except for one
 *
 *
 */

#include<bits/stdc++.h>

using namespace std;
// Naive Linear Search
/*
int getSingleElement(vector<int>&arr){
	int n=arr.size();
	for(int i=0;i<n;i++){
		int num=arr[i];
		int cnt=0;

		for(int j=0;j<n;j++){
			if(arr[j]==num)
				cnt++;
		}
		if(cnt==1)return num;
	}
	return -1;
}
*/
// Map Solution 
/*
int  getSingleElement(vector<int>&arr){
	int n=arr.size();
	map<int,int>omap;
//	unordered_map<int,int>umap;
//	set<int>oset;
//	unordered_set<int>uset;
	for(int i=0;i<n;i++){
		omap[arr[i]]++;
	}


	for(auto it:omap)
		if(it.second==1)
			return it.first;

	return -1;
}
*/
int getSingleElement(vector<int>&arr){
	int n=arr.size();
	int ans=0;
	for(int i=0;i<n;i++)
	{		
		ans^=arr[i];
	}
	return ans;
}
int main(){
	vector<int>arr={4,1,2,1,2};
	int ans=getSingleElement(arr);
	cout<<ans<<endl;
	return 0;
}
