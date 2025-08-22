/*
 * For X non-zero elements copy them into a temp array
 * Now copy back these X non-zero elements to the original array and fill the remaining N-X places with zeros
 *
 *
 *
 *
 *
 *
 */

#include<bits/stdc++.h>
using namespace std;
vector<int>moveZeros(int n, vector<int> a){
	int j=-1;

	for(int i=0;i<n;i++){
		if(a[i]==0){
			j=i;
			break;
		}
	}
	if(j==-1) return a;

	for(int i=j+1;i<n;i++){
		if(a[i]!=0){
			swap(a[i],a[j]);
			j++;
		}
	}

	return a;
}
int main(){
	vector<int> arr={1,0,2,3,2,0,0,4,5,1};
	int n=10;
	vector<int>ans=moveZeros(n,arr);
	for(auto &it:ans)
		cout<<it<<",";
	cout<<"\n";
	return 0;
}
