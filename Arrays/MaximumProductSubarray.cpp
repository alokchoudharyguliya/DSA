#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={2,3,-2,4};
    for(auto &it:arr)
        cout<<it<<",";
    cout<<endl;
    int max_prod=INT_MIN;
    int prod=arr[0];
    for(int i=0;i<arr.size()-1;i++)
    {
        for(int j=i+1;j<arr.size();j++)
        {   
            // for(int k=i;k<=j;k++)
            prod*=arr[j];
            max_prod=max(prod,max_prod);
        }
    }
    cout<<max_prod<<endl;
    return 0;
}