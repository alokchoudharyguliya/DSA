#include<bits/stdc++.h>
using namespace std;
vector<int>insertion(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int temp=arr[i];
        int j=i;
        while(j>=0){
            if(temp<arr[j])
                    arr[j+1]=arr[j];
            j--;
        }
        arr[j]=temp;
        // cout<<temp;
        
    }
    return arr;
}
int main(){
        vector<int>arr={1,2,7,5,4,1,6,3,9};
        arr=insertion(arr);
        for(int i=0;i<arr.size();i++){
            cout<<arr[i];
        }
}