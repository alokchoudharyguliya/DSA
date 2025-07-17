#include<bits/stdc++.h>
using namespace std;
class Solution{

	public:
		void kth_largest_and_smallest_by_ascendingorder(vector<int>&arr, int k){
	sort(arr.begin(),arr.end());
	int n=arr.size();
cout<<arr[n-k]<<",";
cout<<endl;
cout<<arr[k-1]<<",";

		}
};
int main(){
	vector<int>arr={1,2,6,4,5,3};
	Solution obj;
	obj.kth_largest_and_smallest_by_ascendingorder(arr,3);
	return 0;
}
