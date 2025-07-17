#include<bits/stdc++.h>
using namespace std;
void sortK(int arr[],int n, int k){
	
	priority_queue<int, vector<int>, greater<int>>pq; // make a minHeap
	for(int i=0;i<=k;i++)pq.push(arr[i]); // push only first k items of array into the minHeap
					      // Time complexity: klogk to put the k elements into the priority_queue
	int index=0;
	for(int i=k+1;i<n;i++)// iterate for the remaining that is k+1 to n-1 items 
	{
		arr[index++]=pq.top(); // take out the first smallest item within k items from the minHeap and put into the array  index will be smaller than i here and also the k elements we have taken into the minHeap
		pq.pop();
		pq.push(arr[i]); // push the next element into the minHeap
	}
	// Time complexity: (n-k-1)logk -> (n-k)logk
	// as pop and push both have logk time complexity and we are running them for n-k-1 times
	while(pq.empty()==false){ // till the minHeap is not empty obtain the remaining element and put those into the array, they will already be in sorted order
		arr[index++]=pq.top();
		pq.pop();
	}
	// Time Complexity: klogk
for(int i=0;i<n;i++)
	cout<<arr[i]<<",";
}

int main(){
	vector<int>vec={9,8,7,19,18};
	int arr[]={9,8,7,19,18};
	sortK(arr,vec.size(),2);
}
