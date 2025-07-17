#include<bits/stdc++.h>
using namespace std;
int trapRainingwater(vector<int>arr){
	int n=arr.size();
		vector<int>leftMax(n,0);
		vector<int>rightMax(n,0);
		leftMax[0]=arr[0];
		rightMax[n-1]=arr[n-1];
	for(int i=1;i<arr.size();i++){
		leftMax[i]=max(leftMax[i-1],arr[i]);
	}
	for(int i=n-2;i>=0;i--){
		rightMax[i]=max(rightMax[i+1],arr[i]);
	}
	int ans=0;
	for(int i=0;i<n;i++)
	ans+=min(leftMax[i],rightMax[i])-arr[i];
	return ans;
}
int main(){
      vector<int>arr={0,1,0,2,1,0,1,3,2,1,2,1};
      cout<<trapRainingwater(arr);
}
