#include <bits/stdc++.h>
using namespace std;
vector<int>firstandlastoccurrenceofnumber(vector<int>&arr,int tar){
    int low=0,high=arr.size()-1;
    int p1=-1,p2=-1;
    while(low<=high){
        int mid=(low+high)>>1;
        if(arr[mid]<tar){
            low=mid+1;
        }
        else if(arr[mid]>tar)high=mid-1;
        else{
            p1=mid;
            p2=mid;
            break;
        }
    }
    while(p1<arr.size()-1&&arr[p1]==tar)p1++;
    while(p2>0&&arr[p2]==tar)p2--;
    return {p2,p1};
}
int main()
{
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    vector<int> res = firstandlastoccurrenceofnumber(arr, 13);
    cout << res[0] << "," << res[1];
}