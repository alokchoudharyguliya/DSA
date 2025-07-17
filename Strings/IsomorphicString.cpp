#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
		bool isIsomorphic(string u, string t){
			unordered_map<char,char>s;
			for(int i=0;i<u.length();i++){
				char sc=u[i];
				char tc=t[i];

				if(s.count(sc)){
					if(s[sc]!=tc)
						return false;
				}
				else{
					for(auto&pair:s)

					if(pair.second==tc)
						return false;
				}
			}
			return true;
		}
};
int main(){
	string s="egg";
	string t="add";
	Solution sol;
	cout<<sol.isIsomorphic(s,t);
}

