#include<bits/stdc++.h>
using namespace std;
// Naive Approach
/*
int maxProfit(vector<int>&arr){
	int n=arr.size();
	int maxProfi=0;
	for(int i=0;i<n;i++)
	{	
		for(int j=i+1;j<n;j++)
		{
		if(arr[j]-arr[i]>maxProfi){
			maxProfi=arr[j]-arr[i];
		}
		}
	
	}
	return maxProfi;
}
*/

// Optimal Approach

int maxProfit(vector<int>&arr){
	int maxPro=0;
	int n=arr.size();
	int minPrice=INT_MAX;
	for(int i=0;i<n;i++)
	{
	minPrice=min(minPrice,arr[i]);
	maxPro=max(maxPro,arr[i]-minPrice);
	}
	return maxPro;
}
int main(){
	vector<int> arr={7,1,5,3,6,4};
	int maxPro=maxProfit(arr);
	cout<<maxPro<<endl;
	return 0;
}
