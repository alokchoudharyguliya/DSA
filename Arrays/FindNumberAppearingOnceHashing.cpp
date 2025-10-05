// as per the current question there are two ways of hashing, one is simply using the map data structure to maintain the frequency of elements, but here we can also declare a hash array whose indices will work as key for us, having a size as that of maxElement+1.


#include<bits/stdc++.h>
using namespace std;
int getSingleElementUsingCustomHash(vector<int>&arr){
    // find the maximum element
    int maxEle=INT_MIN;
    for(int i=0;i<arr.size();i++){
        maxEle=max(maxEle,arr[i]);
    }
    vector<int>hash(maxEle+1,0);
    for(int i=0;i<arr.size();i++){
        hash[arr[i]]++;
    }
    for(int i=0;i<hash.size();i++)
    if(hash[i]==1)return i;
    return -1;
}

int getSingleElementUsingMap(vector<int>&arr){
    map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    for(auto it:mp)
    if(it.second==1)return it.first;
    return -1;
}

int main(){
    vector<int>arr={4,1,2,1,2};
    // cout<<getSingleElementUsingCustomHash(arr);
    cout<<getSingleElementUsingMap(arr);
}