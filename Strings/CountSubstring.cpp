#include<bits/stdc++.h>
using namespace std;

// substring 
// a,b,c,d,ab,bc,cd,abc,bcd,abcd

int main(){
    string s="abcd";
    cout<<(s.size()*(s.size()+1))/2;
}