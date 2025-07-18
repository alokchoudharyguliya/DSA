#include<bits/stdc++.h>
using namespace std;
void printKClosest(int arr[],int n, int k,int x){
	priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
	for(int i=0;i<k;i++)
		pq.push({abs(arr[i]-x),i});
	for(int i=k;i<n;i++){
		int diff=abs(arr[i]-x);
		if(pq.top().first>diff){
			pq.pop();
			pq.push({diff,i});
		}
	}
	for(int i=0;i<k;i++){
		cout<<pq.top().second<<",";
		pq.pop();
		cout<<endl;
	}
}
int main(){
	int arr[]={30,40,32,33,36,37};
	int x=38;
	int k=3;

	printKClosest(arr,7,k,x);
}
