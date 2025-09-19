#include<bits/stdc++.h>
using namespace std;
void search(string&pat,string&txt){
    int M=pat.size();
    int N=txt.size();
    for(int i=0;i<=N-M;i++){
        int j;
        for(j=0;j<M;j++){
            if(txt[i+j]!=pat[j])break;
        }
        if(j==M)
        cout<<"Pattern found at index "<<i<<endl;
    }
}
int main(){
    string txt1="AABAACAADAABAABA";
    string pat1="AABA";
    cout<<endl;
    search(pat1,txt1);
    string txt2="agd";
    string pat2="g";
    search(pat2,txt2);
    return 0;
}