/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}
// void merge(int a[],int b[],int m,int n)
// {
//     int i=0,j=0;
//     while(i<m&&j<n){
//         if(a[i]<=b[i])
//         {
//             cout<<a[i]<<" ";
//             i++;
//         }
//         else{
//             cout<<b[j]<<" ";
//             j++;
//         }
//     }
//     while(i<m)
// }
int main()
{
    int a=4,b=3;
    swap(a,b);
    // cout<<b<<a;
    // std::cout<<"Hello World";
    bool swapped=false;
    int arr[]={3,5,1,2,40};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
                swapped=true;
            }
        }
        if(swapped==false)
            break;
    }
    
    // for(int t=0;t<5;t++){
    //     int min_ind=t;
    //     for(int j=t+1;j<5;j++){
    //         if(arr[j]>arr[min_ind])
    //         min_ind=j;
    //     swap(arr[min_ind],arr[t]);
    //     }
    // }
    
    // for(int t=1;t<5;t++){
    //     int key=arr[t];
    //     int j=i-1;
    //     while(j>=0&&arr[j]>key)
    //     {
    //         arr[j+1]=arr[j];
    //         j--;
    //     }
    //     arr[j+1]=key;
    // }
    
    vector<pair<int,int>>adj[]={{{1,4},{2,4}},{{0,4},{2,2}},{{0,4},{1,2},{3,3},{4,1},{5,3}},{{2,3},{5,2}},{{2,1},{5,3}},{{2,6},{3,2},{4,3}}};
    for(int i=0;i<5;i++){
        for(auto it:adj[i])
                cout<<it.first<<','<<it.second;
                cout<<endl;
    }
    vector<int>dist(6,INT_MAX);
    priority_queue<pair<int,int>>pq;
    
    // for(int t=0;t<5;t++){
    //     if()
    // }
    return 0;
}