#include<bits/stdc++.h>
using  namespace std;
bool linearSearch(vector<int>&a,int num){
	for(int i=0;i<a.size();i++)
	{
		if(a[i]==num)
			return true;	
	}
	return false;
}

int longestSuccessiveElements(vector<int>&a){
	int n=a.size();
	int longest=1;
	for(int i=0;i<n;i++){
	int x=a[i];
	int cnt=1;
	while(linearSearch(a,x+1)==true){
	x++;
	cnt++;
	}
	longest=max(longest,cnt);
	}
	return longest;
}
int main(){
	vector<int>a={100,200,1,2,3,4};
	int ans=longestSuccessiveElements(a);
	cout<<ans<<endl;
	return 0;
}
