// 1. Use Map -> will keep only the unique count as keys
// 2. Use Set -> will not store the duplicate values
// 3. modified merge sort

#include<bits/stdc++.h>
using namespace std;

// vector<int>unionBySet(vector<int>arr1,vector<int>arr2){
//     set<int>st;
//     for(auto i:arr1){
//         st.insert(i);
//     }
//     for(auto i:arr2){
//         st.insert(i);
//     }
//     vector<int>arr(st.begin(),st.end());
//     return arr;
// }


vector<int>unionByHashMap(vector<int>arr1,vector<int>arr2){
    map<int,int>mp;//we want the elements to not losse their relative order
    
}

int main(){
    vector<int>arr1={1,2,3,4,5};
    vector<int>arr2={2,3,4,4,5};
    vector<int>ans=unionBySet(arr1,arr2);
    for(auto i:ans)
    cout<<i;
}