#include<bits/stdc++.h>
using namespace std;
void merge_sorted_array(int*arr1, int*arr2, int m, int n){
	vector<int> arr3={};
	int o=0,t=0;
	while(o!=m&&t!=n)
	{
		if(arr1[o]<arr2[t])
		{
			arr3.push_back(arr1[o]);
			o++;

		}
		else{
			arr3.push_back(arr2[t]);
			t++;
		}
	}
	while(o!=m)
	{
		arr3.push_back(arr1[o]);
		o++;
	}
	while(t!=n)
	{
		arr3.push_back(arr2[t]);
		t++;
	}
	for(auto it:arr3)
		cout<<it<<",";
	return ;
}
int main(){
	int arr1[]={1,2,3,4};
	int arr2[]={4,5,6};
//	cout<<sizeof(arr2)/sizeof(int*)<<endl<<sizeof(arr1)/(sizeof(int*)<<endl;
	merge_sorted_array(arr1,arr2,sizeof(arr1)/sizeof(arr2[1]),sizeof(arr2)/sizeof(arr1[0]));
}
