#include<bits/stdc++.h>
using namespace std;
int getSingleElement(vector<int> &arr){
	int n=arr.size();
	for(int i=0;i<arr.size();i++){
		int cnt=0;
		for(int j=0;j<arr.size();j++)
		{
			if(arr[i]==arr[j])cnt++;
		}
		if(cnt==1) return arr[i];
	}
	return -1;
}
int main(){
	vector<int> arr1={4,1,2,1,2};
	int ans=getSingleElement(arr1);
	cout<<ans<<endl;
	return 0;
}
