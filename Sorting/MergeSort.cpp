#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int start,int mid,int end){
    int l=start;
    while(l<mid&&r<end){
        if()
    }
    while(r<){

    }

}
vector<int>mergeSort(vector<int>&arr,int start,int end){
    if(start>=end){
        return arr;
    }
    int n=end-start;
    int mid=end+start/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid,end);
    merge(arr,start,mid,end)
    return arr;
}
int main(){
        vector<int>arr={1,2,7,5,4,1,6,3,9};
        arr=mergeSort(arr);
        for(int i=0;i<arr.size();i++){
            cout<<arr[i];
        }
}