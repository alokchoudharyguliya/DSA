#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[]={10,15,7,3,4};
	int x=8;
	int k=2;
	// find k closest numbers to x that is here 2 closest element to 8 that are 10 and 7 
	// first intuition can be calculating the differences and storing the difference and index pair into a minHeap sorted by priority of difference
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;
	for(int i=0;i<5;i++)
	{
		pq.push({abs(x-arr[i]),i});	
	}
	while(k--){
		cout<<arr[pq.top().second]<<endl;
		pq.pop();
	}
}
