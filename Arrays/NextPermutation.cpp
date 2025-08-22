#include<bits/stdc++.h>
using namespace std;
vector<int>nextGreaterPermutation(vector<int>&A){
	int n=A.size();

	// Find the break point - Break point is when a lesser number appears then the lesser number is break point
	int ind=-1;
	for(int i=n-2;i>=0;i--){
		if(A[i]<A[i+1]){
			ind=i;
			break;
		}
	}
	// If break point does not exist
	if(ind==-1)
	{
		reverse(A.begin(),A.end());
		return A;
	}
	for(int i=n-1;i>ind;i--)
	{
		if(A[i]>A[ind]){
			swap(A[i],A[ind]);
			break;}

	}
	reverse(A.begin()+ind+1,A.end());
	return A;

}
int main(){
	vector<int>A={2,1,5,4,3,0,0};
	vector<int>ans=nextGreaterPermutation(A);
	for(auto it:ans)
		cout<<it<<",";
	cout<<endl;
	return 0;
}
