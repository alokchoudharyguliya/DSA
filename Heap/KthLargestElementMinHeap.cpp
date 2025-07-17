#include<bits/stdc++.h>
using namespace std;
int main(){
	int arr[]={5,15,10,20,8,25,18};
	int k=3;
	priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k);	// this minHeap will store the k largest elements seen so far
	for(int i=k;i<7;i++)
	{
		if(arr[i]<pq.top())
			continue;
		pq.pop();
		pq.push(arr[i]);
	}
	while(!pq.empty())
	{
		cout<<pq.top()<<",";
		pq.pop();
	}		cout<<endl;
	// this will reduce the time from (n+klogn) to klogn 
}	
