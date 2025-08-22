/*

	Given an array, print all the elements that are greater than all of the elements on the right side of the array


*/

#include<bits/stdc++.h>
using namespace std;


vector<int>printLeadersBruteForce(int arr[],int n){
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		bool leader=true;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]>arr[i])
			{

				leader=false;
				break;
			}
		}
		if(leader)ans.push_back(arr[i]);

	}
	return ans;
}
vector<int>printLeaders(int arr[],int n){
	vector<int>ans;
	int max=arr[n-1];
	ans.push_back(arr[n-1]);
	for(int i=n-2;i>=0;i--)
		if(arr[i]>max){
			ans.push_back(arr[i]);
	max=arr[i];}
	return ans;
}
int main(){
	int n=6;
	int arr[n]={10,22,12,3,0,6};
//	vector<int>ans=printLeadersBruteForce(arr,n);
	vector<int>ans=printLeaders(arr,n);

	for(int i=ans.size()-1;i>=0;i--)
		cout<<ans[i]<<",";
	cout<<endl;
	return 0;

}
