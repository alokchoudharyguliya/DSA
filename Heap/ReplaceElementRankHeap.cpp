#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		void kth_largest_MaxHeap(vector<int>&arr,int k){
			priority_queue<int>pq;
			int n=arr.size();
			for(int i=0;i<arr.size();i++){
				pq.push(arr[i]);
			}
			int f=k-1;
			while(f>0){
				pq.pop();
				f--;
			}
			cout<<pq.top();
			cout<<endl;
		}
		void kth_smallest_MinHeap(vector<int>&arr,int k){
			priority_queue<int,vector<int>,greater<int>>pq;
			int n=arr.size();
			for(int i=0;i<arr.size();i++){
				pq.push(arr[i]);
			}
			int f=k-1;
			while(f--)pq.pop();
			cout<<pq.top();
			cout<<endl;

		}
};
int main(){
	Solution sol;
	vector<int>arr={1,2,6,4,5,3};
	sol.kth_largest_MaxHeap(arr,3);
	sol.kth_smallest_MinHeap(arr,3);
}
