// maintain a count of open and closing parenthesis
#include<bits/stdc++.h>
using namespace std;
void backtrack(string curr,int open, int close, int n, vector<string>&res){
    if(curr.length()==n<<1){
        res.push_back(curr);
        return;
    }
    if(open<n)backtrack(curr+"(",open+1,close,n,res);
    if(close<open)backtrack(curr+")",open,close+1,n,res);
}
vector<string>generateParenthesis(int n){
    vector<string>res;
    backtrack("",0,0,n,res);
    return res;
}

int main(){
    int n=3;
    vector<string>res=generateParenthesis(n);
    for(string s:res)cout<<s<<",";
}