#include<bits/stdc++.h>
using namespace std;
 int main(){
	vector<int>arr={1,2,4,7,6,3,9,1};
	int low=0;
	int high=arr.size()-1;
	
	int mid=(low+high)/2;
	int k=5;
	int ans=0;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]<k){
			low=mid+1;
		}		
		else{
			ans=mid;
		high=mid-1;	
		}
	}
	cout<<arr[ans]<<endl;
 }
