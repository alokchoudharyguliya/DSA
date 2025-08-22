#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr={2,3,4,7,9};
	int diff=0;
	int k=4;
	int low=0;
	int high=arr.size()-1;
	while(low<=high)
	{	
		int mid=(low+high)/2;
		diff=arr[mid]-mid-1;
		if(diff<k){
			low=mid+1;
		}else
			high=mid-1;
	}

	cout<<k+high+1;


}
