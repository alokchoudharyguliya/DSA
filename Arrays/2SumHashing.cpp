/*
 * Instead of using a loop, we will use a hashMap to check if the other element i.e target-(selected element) exists. 
 * 
 * Select the element of the array one by one using a loop.
 * Then we will check if the other element(ie. target-arr[i])exists in the hashMap.
 * 	If that element exists, then we will return YES for the first variant or we will return the current index and index of the element found using map ie. mp[target-arr[i]]
 *
 * 	If that element does not exist, then we just store the current element in the hashMap along with its index. Because in the future, the current element might be a part of our answer.
 * 	Finally, if we are out of loop, that means there is no such pair whose sum is equal to the target. In this case, we will return either NO or {-1,-1} as per the variant.
 *
 *
 *
 *
 */


#include<bits/stdc++.h>
using namespace std;
/*
string twoSum(int n, vector<int>&arr, int target){
	unordered_map<int,int>mpp;
	for(int i=0;i<n;i++){
		int num=arr[i];
		int moreNeeded=target-num;
		if(mpp.find(moreNeeded)!=mpp.end())return "YES";
		mpp[num]=i;
	}
	return "NO";
}
*/
vector<int>twoSum(int n,vector<int>&arr,int target){
	unordered_map<int,int>mpp;
	for(int i=0;i<n;i++)
	{
		int num=arr[i];
		int moreNeeded=target-num;
		if(mpp.find(moreNeeded)!=mpp.end())
			return {mpp[moreNeeded],i};
		mpp[num]=i;
	}
	return {-1,-1};
}
int main(){
	int n=5;
	vector<int>arr={2,6,5,8,11};
	int target=14;
	string ans=twoSum(n,arr,target);
	cout<<ans<<endl;
	return 0;
}
