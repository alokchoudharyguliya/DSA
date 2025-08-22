/*
 *
 * Using Map
 * Storing the frequencies,
 * Why not unordered_map -> Because we want the elements in sorted order
 *
 *
 *
 * Using Set
 *
 *
 *
 *
 *
 * Using Two Pointers
 * Above two solutions don't make use the fact that given arrays are already sorted rather they explicitly maintain sorted data structures, So the above solutions will also work even if the two arrays are not sorted
 *
 *
 */


#include<bits/stdc++.h>
using namespace std;

vector<int> findUnionMap(int arr1[],int arr2[], int n, int m){
	map<int,int>freq;

	vector<int>Union;
	for(int i=0;i<n;i++)
		freq[arr1[i]]++;
	for(int i=0;i<m;i++)
		freq[arr2[i]]++;
	for(auto &it:freq)
		Union.push_back(it.first);
	return Union;
}

vector<int>findUnionSet(int arr1[],int arr2[],int n,int m){
	set<int>unionSet;
	vector<int>Union;
	for(int i=0;i<n;i++)
		unionSet.insert(arr1[i]);
	for(int i=0;i<m;i++)
		unionSet.insert(arr2[i]);
	for(auto &it:unionSet)
		Union.push_back(it);
	return Union;
}
vector<int> findUnionTwoPointer(int arr1[], int arr2[], int n, int m){
	int i=0, j=0;
	vector<int> Union;
	while(i<n && j<m){
		if(arr1[i]<=arr2[i])
		{
			if(Union.size()==0|| Union.back()!=arr1[i])
				Union.push_back(arr1[i]);
			i++;
		}
		else{
			if(Union.size()==0||Union.back()!=arr2[j])
				Union.push_back(arr2[j]);
			j++;
		}
	 }
	while(i<n){
		if(Union.back()!=arr1[i])
			Union.push_back(arr1[i]);
		i++;
	}
	while(j<m){
		if(Union.back()!=arr2[j])
			Union.push_back(arr2[j]);
		j++;
	}
	return Union;
}
int main(){
	int n=10, m=7;
	int arr1[]={1,2,3,4,5,6,7,8,9,10};
	int arr2[]={2,3,4,4,5,11,12};
	vector<int>Union=findUnionMap(arr1,arr2,n,m);
//	vector<int>
		Union=findUnionSet(arr1,arr2,n,m);
	cout<<"Union of arr1 and arr2 is "<<endl;
	for(auto &val:Union)
		cout<<val<<",";
	return 0;
}

