// Rotate by k positions
// 1. Using a temp array
// 2. Observation based 
// reverse the last k elements, reverse the n-k first elements, then reverse the whole array

#include<bits/stdc++.h>
using namespace std;

void Reverse(int arr[],int start,int end){
    // using 2 pointers and swap 
    // start at left side and end from right side of array
    while(start<=end){
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void RotateRight(int arr[],int n,int k){
    // reverse the first n-k elements
    Reverse(arr,0,n-k-1);
    // reverse last k elements
    Reverse(arr,n-k,n-1);
    // reverse the whole array
    Reverse(arr,0,n-1);

}
int main(){
    int arr[]={1,2,3,4,5,6,7,7};
    int n=8;
    int k=2;
    RotateRight(arr,n,k);
    printArray(arr);
}