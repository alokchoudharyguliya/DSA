#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>triplet(int n,vector<int>&arr){
	vector<vector<int>>ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		if(

}
int main(){

	vector<int>arr={-1,0,1,2,-1,-4};
	int n=arr.size();
	vector<vector<int>>ans=triplet(n,arr);
	for(auto it:ans){
	cout<<"[";
	for(auto i:it)
		cout<<i<<",";
	cout<<"]";
	}
	cout<<endl;
	return 0;
}
