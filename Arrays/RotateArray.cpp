// Rotate by k positions
// 1. Using a temp array
// 2. Observation based 
// reverse the last k elements, reverse the n-k first elements, then reverse the whole array
#include<bits/stdc++.h>
using namespace std;
void RotateRight(int arr[],int n,int k){
    if(n==0)return;
    k=k%n;
    if(k>n)return ;

    int temp[k];
    for(int i=n-k;i<n;i++)temp[i-n+k]=arr[i];

}