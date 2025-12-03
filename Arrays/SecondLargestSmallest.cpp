/*
 * Finding the second smallest and second largest
 * 1. Sort in ascending order and then select second element from starting and second element from ending but this will fail if there are more than one occurrences of largest or smallest
 *
 *
 * 2. Instead find the largest and smallest in one traversal and then once again traverse to find an element just greater than the smallest and the element just smaller than the largest
 *
 *
 * 3. Best is to use 4 different pointers for largest, largest2, smallest, smallest2 and find them respectively
 *
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int>arr={1,7,4,2,6,3,9};
	int small=INT_MAX,small_sec=INT_MAX;
	int large=INT_MIN,large_sec=INT_MIN;

	for(int i=0;i<arr.size();i++){
		if(arr[i]<small){
			small_sec=small;
			small=arr[i];
		}
		else if(arr[i]<small_sec&&arr[i]!=small){ // we want small and small_sec to be different
			small_sec=arr[i];
		}
	}
	cout<<small_sec;
	for(int i=0;i<arr.size();i++){
		if(arr[i]>large){
			large_sec=large;
			large=arr[i];
		}
		else if(arr[i]>large_sec&&arr[i]!=large){ // we want small and small_sec to be different
			large_sec=arr[i];
		}
	}
	cout<<large_sec;
	return 0;
}
