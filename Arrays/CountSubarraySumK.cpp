// Given an array of integers and an integer k, return the total number of subarrays whose sum equals k
// A subarray is a contiguous non-empty sequence of elements within an array.


#include<bits/stdc++.h>
using namespace std;
/*
int findAllSubarraysWithGivenSum(vector<int>&arr, int k){

	int n=arr.size();
	int cnt=0;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){

		int sum=0;
		for(int K=i;K<=j;K++)
			sum+=arr[K];

		if(sum==k)
			cnt++;
		}

	}
	return cnt;
}
*/
/*
int findAllSubarraysWithGivenSum(vector<int>&arr,int k){
	int n=arr.size();
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		int sum=0;
	for(int j=i;j<n;j++)
	{
		sum+=arr[j];
		if(sum==k)
			cnt++;
	}
	}
	return cnt;
}
*/

// Concept of Prefix Sum
// The overall concept is to keep the prefixSum which will help us to find the intermediate subarray that sums to target
int findAllSubarraysWithGivenSum(vector<int>&arr, int k){
	int n=arr.size();
	unordered_map<int,int> mpp;
	int preSum=0;
	int cnt=0;
	mpp[0]=1;
	for(int i=0;i<n;i++){

		preSum+=arr[i];

		int remove=preSum-k;
		cnt+=mpp[remove];
		mpp[preSum]+=1;
	}
	return cnt;

}
int main(){
//	vector arr={3,1,2,4};
	vector arr={1,2,3,-3,1,1,1,4,2,-3};
	int k=3;
	int cnt=findAllSubarraysWithGivenSum(arr,k);
	cout<<cnt<<endl;
	return 0;
}
