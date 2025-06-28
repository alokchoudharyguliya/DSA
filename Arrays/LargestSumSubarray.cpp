/*
 * Look for all positive contiguous segments of the array(max_ending_here)
 * Keep the track of maximum sum contiguous segment among all the positive segments(max_so_far)
 * Each time we get a positive sum compare it with max_so_far and if it is greater than max_so_far, update max_so_far
 * a negative number will only reduce the sum
 */
/*
int largestSum(int arr, n){
	max_so_far=INT_MIN;
	max_ending_here=0;
	for(int i=0;i<n;i++)
	{
		max_ending_here+=arr[i];
		if(max_so_far<max_ending_here)
			max_so_far=max_ending_here;
		if(max_ending_here<0)
			max_ending_here=0;

	}
	return max_so_far;
}*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[]={-3,4,-1,-2,1,5};
	int maxGlobal=INT_MIN,maxSoFar=0;
	for(int i=0;i<6;i++)
	{
		maxSoFar+=arr[i];
		if(maxGlobal<maxSoFar)
			maxGlobal=maxSoFar;
		if(maxSoFar<0)
			maxSoFar=0;
	}
	cout<<maxGlobal<<endl;
}
