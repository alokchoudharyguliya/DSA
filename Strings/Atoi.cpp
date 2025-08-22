#include<bits/stdc++.h>
using namespace std;
int Atoi(string s){
    if(s.empty())return 0;
    int n=s.length();
    int i=0;
    while(i<n && s[i]==' '){
        i++;
    }
    if(i==n)return 0;
    int sign=1;
    if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
        }
        long long res=0;
        long long ans=0;
        while(i<n&&isdigit(s[i])){
            int digit=s[i]-'0';
            res=res*10+digit;
            ans=sign*res;
            if(ans<=INT_MIN)
            return INT_MIN;
            if(ans>=INT_MAX)
            return INT_MAX;
            i++;
        }
        return static_cast<int>(ans);
}
int main(){
    string s;
    cin>>s;
    cout<<Atoi(s);
}