#include<bits/stdc++.h>
using namespace std;
vector<int>findUnion(vector<int>&arr1,vector<int>&arr2,int n,int m){
    set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<m;i++){
        st.insert(arr2[i]);
    }
    vector<int>unionArr(st.begin(),st.end());
    return unionArr;
}
vector<int>findUnionTwoPointer(vector<int>&arr1,vector<int>&arr2,int n,int m){
    vector<int>Union;
    int i=0,j=0;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            if(Union.empty()||Union.back()!=arr1[i]) // Union must have some elements before checking the last element, if the Union is empty then we need not check, simply push the element
            Union.push_back(arr1[i]);
            i++;
        }
        else if(arr1[i]>arr2[j]){
            if(Union.empty()||Union.back()!=arr2[j])
            Union.push_back(arr2[j]);
            j++;
        }
        else{
            if(Union.empty()||Union.back()!=arr2[j])
            Union.push_back(arr1[i]);
            i++,j++;
        }
    }
    while(i<n){
        if(Union.empty()||Union.back()!=arr1[i])
        Union.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        if(Union.empty()||Union.back()!=arr2[j])
        Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}
int main(){
    // int arr1[]={1,2,3,4,5,6,7,8,9,10};
    // int arr2[]={2,3,4,4,5,11,12};
    vector<int>arr1={1,2,3,4,5,6,7,8,9,10};
    vector<int>arr2={2,3,4,4,5,11,12};
    int n=arr1.size();
    int m=arr2.size();
    // vector<int>res=findUnion(arr1,arr2,n,m);
    vector<int>res=findUnionTwoPointer(arr1,arr2,n,m);
    for(int val:res)
        cout<<val<<",";
}