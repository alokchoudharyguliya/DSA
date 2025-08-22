#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr={4,5,1,2,3};
	int tar=2;
	int low=0;
	int high=arr.size()-1;
	int mid=(low+high)/2;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==tar)
			break;
	if(arr[low]<=arr[mid])
	{
		// means we are in the totally sorted array
		if(arr[mid]>=tar&&arr[low]<=tar){
			// means this half contains the element
			high=mid-1;
		}
		else low=mid+1;
	}
	else{
		if(arr[mid]<=tar&&arr[high]>=tar)
			low=mid+1;
		else
			high=mid-1;
	}


	}
	cout<<arr[mid];

}
