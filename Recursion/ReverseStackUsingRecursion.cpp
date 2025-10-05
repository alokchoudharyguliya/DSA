#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int topVal=s.top();
    s.pop();
    insertAtBottom(s,val);
    s.push(topVal);
}
void reverseStack(stack<int>&s){
    if(s.empty())return;
    int topVal=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,topVal);
}
int main(){
    stack<int>s;
    s.push(4);
    s.push(1);
    s.push(2);
    s.push(3);
    reverseStack(s);
    while(!s.empty()){
        cout<<s.top()<<",";
        s.pop();
    }
}