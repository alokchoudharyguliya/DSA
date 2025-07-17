#include<bits/stdc++.h>
using namespace std;
void sortK(int arr[],int n, int k){

	priority_queue<int, vector<int>, greater<int>>pq; // make a minHeap
	for(int i=0;i<=k;i++)pq.push(arr[i]); // push only first k items of array into the minHeap
	int index=0;
	for(int i=k+1;i<n;i++)// iterate for the remaining that is k+1 to n-1 items 
	{
		arr[index++]=pq.top(); // take out the first smallest item within k items from the minHeap and put into the array  index will be smaller than i here and also the k elements we have taken into the minHeap
		pq.pop();
		pq.push(arr[i]); // push the next element into the minHeap
	}
	while(pq.empty()==false){ // till the minHeap is not empty obtain the remaining element and put those into the array, they will already be in sorted order
		arr[index++]=pq.top();
		pq.pop();
	}
}

int main(){
	vector<int>vec={};
	int arr[]={};
	sortK(arr,vec.size(),2);
}
