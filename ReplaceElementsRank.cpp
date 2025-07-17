/*
 * Given an array of N integers, the task is to replace each element of the array by its rank in the array
 * 
 * for each element in the array find how many elements are smaller than a particular element
 * That is for 20,15,26,2,98,6
 * find how many elements are there that are smaller than current element we again and again store elements in the set each iteration the set stores the elements that are lesser than current element
 * say in iteration for 15, set will store 2, 6 so the rank will be 3
 *
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=6;
	int  arr[n]={20,15,26,2,98,6};
	for(int i=0;i<n;i++){
		set<int>s; // it is an ordered set
		for(int j=0;j<n;j++){
			if(arr[j]<arr[i])
				s.insert(arr[j]);
		}
	cout<<s.size()+1<<" ";
	}
}
