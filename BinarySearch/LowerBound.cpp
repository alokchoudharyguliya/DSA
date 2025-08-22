#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr={3,5,8,11,19};
	int low=0;
	int high=arr.size()-1;
	int tar=9;
	int ans=0;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]<=tar){
			ans=arr[mid];
			low=mid+1;}
		else if(arr[mid]>tar){
			high=mid-1;
		}
		
	}
	cout<<ans;

}
