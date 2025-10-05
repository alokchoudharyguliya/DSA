/*
 * Given an integer N and an array of size N-1 containing N-1 numbers between 1 to N.
 * 
 * Number(between 1 to N), that is not present in the given array.
 *
 *
 */
// XOR method
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr={3,0,1};
	// we will simply take xor till elements N that is the size of the array
	int ans=arr.size();
	for(int i=0;i<arr.size();i++)
		ans=ans^i^arr[i];
	cout<<ans;
	return 0;
}
