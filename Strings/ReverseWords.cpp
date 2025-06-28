#include<bits/stdc++.h>
using namespace std;
int main(){
	string str="Alok was here where were you ?";
//	cin>>str;
	cout<<str<<endl;
	stack<string>strStack;
int i=0;
int start=0;
int end=start;
while(i<str.length()){
	if(str[i]==' ')
	{	
		strStack.push(str.substr(start,i-start));
		start=i+1;
	}
//		end++;
	i++;
}
string newStr="";
strStack.push(str.substr(start,i-start+1));
while(!strStack.empty()){
	newStr+=strStack.top();
	strStack.pop();
	if(!strStack.empty())
		newStr+=" ";
	}
	cout<<newStr;
	return 0;
}
