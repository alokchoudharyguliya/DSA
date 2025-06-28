#include<bits/stdc++.h>
using namespace std;
bool anagram(string str1, string str2){
	if(str1.length()!=str2.length())
		return false;

	sort(str1.begin(),str1.end());
	sort(str2.begin(),str2.end());
	for(int i=0;i<str1.length();i++)
		if(str1[i]!=str2[i])
			return false;
	
	return true;
}
int main(){
	string str1="ABCD";
	string str2="BADC";
anagram(str1, str2)?cout<<"YES"<<endl:cout<<"NO"<<endl;
	return 0;
}
