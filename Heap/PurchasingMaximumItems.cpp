#include<bits/stdc++.h>
using namespace std;
//void buildHeap(int*arr){
//	pick the i-2/2 the element that is bottom and right most inner node
//	for(int i=(arr.size()-2)/2;i>=0;i--)
//	{
//	callHeapify on the array	
//	}
//}
int main(){
	// we have in all sum money and we want to purchase maximum count item that is maximum number of items using the sum amount
	int cost[]={1,12,5,111,200};
	int sum=10;
	// 1. One way is to directly sort and then look for whether we can pick it or not
//	sort(cost,cost+5);
//	int cnt=0;
//	for(int i=0;i<5;i++){
//			cout<<cost[i]<<",";
//	if(sum<0||sum-cost[i]<0) break;
//	sum-=cost[i];
//	cnt++;}
//	cout<<endl;
//	cout<<cnt;
	// But this solution requires modification of the initial array
	// Takes nlogn time; n:number of items in the array
	//
	// 2. Other approach is to convert the array into a binary heap, binary heap requires logn time for push and pop while O(1) time for top operation
	 // Binary heap means that we will be using the array only and we will rearrange the positions of elements to satisfy the minHeap condition


	// buildHeap(arr); // THIS IS OUR SELF DECLARED BUILDHEAP FUNCTION TO GET THE ELEMENTS ARRANGED IN THE INITIAL ARRAY ITSELF
	priority_queue<int,vector<int>,greater<int>>pq(cost,cost+5);
	// using a priority_queue uses extra space of O(n)
	int cnt=0;
	while(sum>=0)
	{
		int costMin=pq.top();
		if(sum-costMin<0)break;
		sum-=costMin;
		pq.pop();
		cnt++;
	}
	cout<<cnt<<endl;

	// Time complexity: O(n) -> building the heap
	// 		    O(res*logn)->removing items from the heap 
	// 		    res might be lesser than n therefore this heap based approach is better than sorting based approach
	// as we are using the same array itself therefore no extra space
}

