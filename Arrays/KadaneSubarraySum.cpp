// Kadane Algorithm
// The intuition is to not consider the subarray as a part of the answer if its sum is less than 0.
// A subarray with sum less than 0 will always reduce our answer and so this type of subarray cannot be part of the subarray with maximum sum.
//
//
#include<bits/stdc++.h>
using namespace std;
long long maxSubarraySum(int arr[],int n){
	long long maxi=LONG_MIN;
	long long sum=0;
	int start=0,end=-1,ansStart=-1;
	for(int i=0;i<n;i++){
		sum+=arr[i];
		if(sum==0) start=i;
		if(sum>maxi){
			maxi=sum;end=i;
			ansStart=start;
		}
		if(sum<0){
//			start=i;
			sum=0;
		}
	}
	cout<<ansStart<<","<<end<<endl;
	return maxi;
}
int main(){
	int arr[]={-2,1,-3,4,-1,2,1,-5,4};
	int n=sizeof(arr)/sizeof(arr[0]);
	long long maxSum=maxSubarraySum(arr,n);
	cout<<maxSum<<endl;

	return 0;
}
