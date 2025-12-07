#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool rotateString(string&s, string&goal){
        if(s.length()!=goal.length()){
            return false;
        }
        for(int i=0;i<s.length();i++){
            string rotated=s.substr(i)+s.substr(0,i);
            cout<<rotated<<",";
            if(rotated==goal)
            return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    string s="rotation";
    string goal="tionrota";
    if(sol.rotateString(s,goal))
    cout<<"True"<<endl;
    else
    cout<<"False"<<endl;
}