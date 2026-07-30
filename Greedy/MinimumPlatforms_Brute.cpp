#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
  int countPlatforms(int n,int arr[],int dep[])
{
  int ans=1;
  for(int i=0;i<n;i++)
    {
      int count=1;
      for(int j=i+1;j<n;j++)
        {
  if((arr[i]>=arr[j]&&arr[i]<=dep[j])||(arr[j]>=arr[i]&&arr[j]<=dep[i])){
    count++;
  }
        }
      ans=max(ans,count);
    }
  return ans;
}
};
int main(){
  int arr[]={900,945,955,1100,1500,1800};
  int dep[]={920,1200,1130,1150,1900,2000};
  int n=sizeof(arr)/sizeof(arr[0]);
  Solution obj;
  cout<<obj.countPlatforms(n,arr,dep);
}
