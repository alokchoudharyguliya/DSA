// Sort the array and try to choose the  numbers in a greedy way.
// Keep a left pointer at the first index and a right pointer at the last index.
// Now until left<right, we check the sum of arr[left] and arr[right].
// Now if the sum<target, we need bigger numbers and so we increment the left pointer.
// But if sum>target, we ned to consider lesser numbers and so we will decrement the right pointer.
//
//
#include<bits/stdc++.h>
using namespace std;
/*
string twoSumTwoPointer(vector<int>&arr,int target){
	int left=0, right=arr.size()-1;
	sort(arr.begin(),arr.end());
	while(left<right){
		int sum=arr[left]+arr[right];
		if(sum==target)
			return "YES";
		else if (sum<target)
			left++;
		else 
			right--;
	}
	return "NO";
}
*/
vector<int>twoSumTwoPointer(vector<int>&arr,int target){
	int left=0, right=arr.size()-1;
	sort(arr.begin(),arr.end());
	while(left<right){
	int sum=arr[left]+arr[right];
	if(sum==target)
		return {arr[left],arr[right]};
	else if (sum<target)
		left++;
	else right--;
	}
	return {-1,-1};
}
int main(){
	vector<int>arr={4,1,2,3,1};
//	string ans=twoSumTwoPointer(arr,5);
	vector<int>ans=twoSumTwoPointer(arr,5);

//	cout<<ans<<endl;
	cout<<ans[0]<<","<<ans[1]<<endl;
	return 0;
}
