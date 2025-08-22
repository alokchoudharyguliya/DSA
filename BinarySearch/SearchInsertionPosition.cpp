#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr={1,2,3,3,8,9,11};
	int tar=8;
	int low=0;
	int ans=0;
	int target=10;
	int high=arr.size()-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]<target){
			low=mid+1;
		}
		else{
			ans=mid;
			high=mid-1;
		}
	}
	cout<<ans<<"\n";
}
