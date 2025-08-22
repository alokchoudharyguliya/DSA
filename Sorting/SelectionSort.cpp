#include<bits/stdc++.h>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
vector<int>selection(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int smallInd=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[smallInd])
            smallInd=j;
        }
        swap(arr[i],arr[smallInd]);
    }
    return arr;
}
int main(){
        vector<int>arr={1,2,7,5,4,1,6,3,9};
        arr=selection(arr);
        for(int i=0;i<arr.size();i++){
            cout<<arr[i];
        }
}