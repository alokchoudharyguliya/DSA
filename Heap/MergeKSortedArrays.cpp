#include<bits/stdc++.h>
using namespace std;
//
// Value, Position of Array, Position of Value in array
// Extract Min and Insert next item of the same array
//
//
//
struct Triplet{
	int val,aPos, vPos;
	Triplet(int v,int ap,int vp){
		val=v;
		aPos=ap;
		vPos=vp;
	}
};
struct myCmp{
	bool operator()(Triplet st1,Triplet st2){
		return st1.val>st2.val;
		// id true is returned from here then there will be swapping else no swapping
		// in this case t1.val>t2.val means if this condition is satisfied that is 
		// prior element is greater than following element then we swap that is we will keep lesser 
		// element first that is ascending order
}
};

int main(){
	vector<int>res;
	vector<int>arr[3]={{10,20},{5,15},{4,9,11}};
//	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
	priority_queue<Triplet,vector<Triplet>,myCmp>pq;
	for(int i=0;i<3;i++)
	{
	Triplet t(arr[i][0],i,0); // push all the first elements that is from all the subarrays the first element, store the array's position and also the position of the element
	pq.push(t);

	}	
	while(!pq.empty()){
		Triplet curr=pq.top();pq.pop(); // extract the minimum element that is top element of priority queue
		res.push_back(curr.val); // push the popped element into the result
		int ap=curr.aPos, vp=curr.vPos; // now from the popped element's array pos and its position in array 
						// 1. apos will help to find the array and vpos will help to find the next element
		if(vp+1<arr[ap].size())		// tilll the vpos is lesser than size of the array itself
		{
			Triplet t(arr[ap][vp+1],ap,vp+1);
			pq.push(t); // push the element into the priority queue
		}
	}
	for(auto it:res)
		cout<<it<<",";
	return 0;

}
