#include<bits/stdc++.h>
using namespace std;

class maxHeap{
	int size;
	int capacity;
//	int arr[];
	
	maxHeap(int sizeA):size(0),capacity(sizeA){}
//	void insert(int num){
//		if(size==0)
		
	
//	}
	int left(int i);
	int right(int i);
	int parent(int i);
};
void maxHeapify(vector<int>&arr,int n, int i){
	int largest=i,left=2*i+1, right=2*i+2;
	if(left<n&&arr[left]>arr[largest]) largest=left;
	if(right<n&&arr[right]>arr[largest])largest=right;
	if(largest!=i)
	{
		swap(arr[largest],arr[i]);
		maxHeapify(arr, n, largest);
	}
}
void buildHeap(vector<int>&arr,int size){
	for(int i=(size-2)/2;i>=0;i--)
		maxHeapify(arr,size,i);
	cout<<endl;
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<",";
}

int maxHeap::left(int i){
	return 2*i+1;
}
int maxHeap::right(int i){
	return 2*i+2;
}
int maxHeap::parent(int i){
	return 0;
}
int main(){
	vector<int> arr={10,15,50,4,20};
//	maxHeap mx(arr.size());
	buildHeap(arr,arr.size());
	cout<<endl;
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<",";
	for(int i=arr.size()-1;i>=0;i--)
	{
		swap(arr[i],arr[0]);
		maxHeapify(arr,i,0);
	}
	for(int i=0;i<arr.size();i++)

		cout<<arr[i]<<",";
}
