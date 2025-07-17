#include<bits/stdc++.h>
using namespace std;
// Heap internally uses dynamic size arrays in libraries
struct Person{
	int age;
	float ht;
	Person(int a, float h){
		age=a;
		ht=h;
	}
};
struct myCmp{
	// Overload the () operator to compare two Person objects
   // bool operator()(const Person& p1, const Person& p2) {
        // For max-heap (taller people have higher priority)
     //   return p1.getHeight() < p2.getHeight();

        // For min-heap (shorter people have higher priority), use:
        // return p1.getHeight() > p2.getHeight();
//    }
	bool operator()(Person const &p1, Person const&p2){
		p1.ht<p2.ht;
	}
}	
class MinHeap{
	public:
//	MinHeap(int c):arr(new int[c]),size(0),capacity(c){}
	MinHeap(int c){
		arr=new int[c];
		size=0;
		capacity=c;
	}
	int left(int i);
	int right(int i);
	int parent(int i);
	void insert(int x);
	int minHeapify(int n);
	int extractMin();
	void decreaseKey(int i, int x){
	arr[i]=x;
//	cout<<"Heu";
	while(i!=0&&arr[parent(i)]>arr[i]){
//		cout<<"out";
		swap(arr[i],arr[parent(i)]);
		i=parent(i);
	}
	}
	int deleteEl(int i){
		/*
		int del=arr[i];
		int left=2*i+1;
		int right=2*i+2;
		int smallest=i;
		while(i<size){
			if(arr[smallest]<arr[left])
				smallest=left;
			if(arr[smallest]<arr[right])
				smallest=right;
//			int smallest=min(arr[left],min(arr[right],arr[i]);
			swap(arr[smallest],arr[i]);
		}
		*/
//		cout<<"Hey";
		this->decreaseKey(i,INT_MIN);
		return this->extractMin();
	}
	int*arr;
	int size;
	int capacity;
};

int MinHeap::left(int i){
	return 2*i+1;
}
int MinHeap::right(int i){
	return 2*i+2;
}
int MinHeap::parent(int i){
	return (i-1)/2;
}
void MinHeap::insert(int x){
	if(size==capacity)return;
	size++; arr[size-1]=x;
	for(int i=size-1;i!=0&&arr[parent(i)]>x;){
		swap(arr[i],arr[parent(i)]);
		i=parent(i);
	}
}
int MinHeap::minHeapify(int i){
	int leftCh=left(i), rightCh=right(i);
	int smallest=i;	
	if(leftCh<size && arr[leftCh]<arr[i])
		smallest=leftCh;
	if (rightCh<size&&arr[rightCh]<arr[i])
		smallest=rightCh;

	if(smallest!=i){
		swap(arr[i],arr[smallest]);
		minHeapify(smallest);
	
	}
	return 0;
}
int MinHeap::extractMin(){
// 	if(Heap gets empty) return INT_MAX;
	if(size==0)return INT_MAX;
	// we explicitly call this case of size==1 because we don't want to call minHeapify for size=0 minHeap
	if(size==1){
		size--;
		return arr[0];
	}
//	arr[0]=INT_MAX;
	swap(arr[0],arr[size-1]);
	minHeapify(0);
	size--;
//	cout<<"cout";
	return arr[size];
}
// top, empty->O(1)
// push, pop->O(logn)
//
int  main(){
	int n=10;

	MinHeap mn(n);
	mn.insert(2);
	mn.insert(1);
	mn.insert(12);
	mn.insert(14);

	/*
	 * while(mn.size)
	{
		cout<<mn.extractMin()<<",";
	}
	cout<<endl;
	*/
	mn.deleteEl(2);

	while(mn.size)
	{
		cout<<mn.extractMin()<<",";
	}
	priority_queue<int>pq; // maxHeap default is maxElement at top
	int arr[]={1,2};
	priority_quueue<int,vector<int>, greater<int>> minHeap(arr,arr+2); //  iterator to the first element of array and the iterator to one position after the last element
									   //  Time complexity of one by one inserting the elements into the maxHeap/Priority_Queue is higher than copying using the constructor as given 
	pq.push(10);
	cout<<pq.size();
	while(pq.empty()==false){
		cout<<pq.top()<<",";
		pq.pop();
	}
	// one trick to obtain a minHepa from a maxHeap is to multiply the elements with -1 and then store into the priority_queue and again multiply with -1 when retrieving back
	priority_queue<Person, vector<Person>, myCmp>pq;
}
