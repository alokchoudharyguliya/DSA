/*
 * 100, 200, 1, 3, 2, 4
 *
 * Longest consecutive subsequence is 1, 2, 3, and 4
 *
 */

#include<bits/stdc++.h>
using namespace std;
bool linearSearch(vector<int>&a, int num){
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]==num)
			return true;
	}
	return false;
}
/*
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
*/

/*
int longestSuccessiveElements(vector<int>&a){

	int n=a.size();
	if(n==0)return 0;
	sort(a.begin(),a.end());
	
	for(int i=0;i<n;i++)
	{
		if(a[i]-1==lastSmaller)
		{
			cnt+=1;
			lastSmaller=a[i];
		}
		else if(a[i]!=lastSmaller){
			cnt=1;
			lastSmaller=a[i];
		}
		longest=max(longest,cnt);
	}
	return longest;
}
*/
int longestSuccessiveElements(vector<int>&a){
	int n=a.size();
	if(n==0) return 0;
	int longest=1;
	unordered_set<int>st;

	for(int i=0;i<n;i++)
		st.insert(a[i]);
	for(auto it:st){
	// 1 check for 0 zero found means continue if 0 not found 1 is starting
	if(st.find(it-1)==st.end()){
	int cnt=1;
	int x=it;
	// for a new number say 1 find all the continuous sequences keep checking till you don't find the next number
	while(st.find(x+1)!=st.end()){
	x++;
	cnt++;
	}
	longest=max(longest, cnt);
	}
	}
	return longest;
}
int main(){
	vector<int>a={100,200,1,2,3,4};
	int ans=longestSuccessiveElements(a);
	cout<<ans<<endl;
	return 0;
}
