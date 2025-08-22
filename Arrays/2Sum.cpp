// Return YES if there exist two numbers such that their sum is equal to the target, otherwise NO
// Return indices of the two numbers such that their sum is equal to the target, otherwise {-1,-1}
// 
// NOT ALLOWED TO USE THE SAME ELEMENT TWICE
//
//
//
//
// For each element of the given array, we will try to search for another element such that its sum is equal to the target. 
//
//
#include<bits/stdc++.h>
using namespace std;
string twoSum(int n, vector<int>&arr,int target){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n; j++){
			if(arr[i]+arr[j]==target)
				return "YES";
		}
	}
	return "NO";
}
vector<int>twoSum(int n, vector<int>&arr, int target){
	vector<int> ans;
	for(int i=0;i<nli++){
		for(int j=i+1;j<n;j++){
		if(arr[i]+arr[j]==target){
			ans.push_back(i);
			ans.push_back(j);
			return ans;
		}
		}

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
