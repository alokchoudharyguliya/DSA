#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool rotateString(string&s,string&goal){
        if(s.length()!=goal.length())return false;
        string doubleS=s+s;
        return doubleS.find(goal)!=string::npos;
    }
};
int main(){
    Solution sol;
    string s="rotation";
    string goal="tionrota";
    cout<<(sol.rotateString(s,goal)?"TRUE":"FALSE")<<endl;
}