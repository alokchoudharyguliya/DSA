#include<bits/stdc++.h>
using namespace std;
int trapRainingWater(vector<int>arr){
	stack<int>st;
	int n=arr.size();
	int water=0;
	for(int i=0;i<n;i++)
	{
		while(!st.empty() && arr[i]>arr[st.top()])
		{	
			int top=st.top();
			st.pop();
			if(st.empty())
				break;
//			int distance=i-st.top()-1;
			int bounded_height=min(arr[st.top()],arr[i])-arr[top];
//			cout<<distance<<","<<bounded_height;
			cout<<endl;
			int distance=1;
			water+=distance*bounded_height;
		}
		st.push(i);
	}
	return water;

}
int main(){
	vector<int>arr={0,1,0,2,1,0,0,3,2,1,2,1};
	cout<<trapRainingWater(arr);
}
