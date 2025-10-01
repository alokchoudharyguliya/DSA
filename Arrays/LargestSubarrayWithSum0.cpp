// Given an array containing both positive and negative integers, we have to find the **length** of the longest subarray with the sum of all elements equal to zero.
#include<bits/stdc++.h>
using namespace std;

// naive - O(N^2)
int solve(vector<int>&v){
    int maxLen=0;
    for(int i=0;i<v.size();i++){
        int sum=0;
        int j;
        for(j=i;j<v.size();j++){
            sum+=v[j];
        }
        if(sum==0){
            maxLen=max(maxLen,j-i);
        }
    }

    return maxLen;
}

// // optimized code - using the prefix sum concept
// int solve(vector<int>&v){
//     int maxLen=0;
//     unorderd_map<int,int>sumIndexMap;
//     int sum=0;
//     for(int i=0;i<v.size();i++){
//         sum+=a[i];
//         if(sum==0){
//             maxLen=i+1;
//         }
//         else if(sumIndexMap.find(sum)!=sumIndexMap.end()){
//             maxLen=max(maxLen,i-sumIndexMap[sum]);
//         }
//         else 
//             sumIndexMap[sum]=i;
//     }
//     return maxLen;
// }
int main(){
    vector<int>v={9,-3,3,-1,6,-5};
    cout<<solve(v)<<endl;
}