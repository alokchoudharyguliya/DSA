// we have an int n and we need to generate all possible valid paranthesis combinations for that n number of "()" pairs
// going for the brute force that is generate all the combinations and then return only the valid ones after passing via a validator
#include<bits/stdc++.h>
using namespace std;
bool isValid(string s){
    int balance=0;
    for(char c:s){
        if(c=='(')balance++;
        else balance--;
        if(balance<0)return false;
    }
    return balance==0;
}
void generateAll(string curr, int n,vector<string>&res){
    if(curr.length()==n<<1){
        if(isValid(curr))res.push_back(curr);
        return;
    }
    
    generateAll(curr+"(",n,res);
    generateAll(curr+")",n,res);
}

vector<string>generateParenthesis(int n){
    vector<string>res;
    generateAll("",n,res);
    return res;
}
int main(){
    int n=3;
    vector<string>res=generateParenthesis(n);
    for(string s:res)
    cout<<s<<endl;
}