#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return (int)res;
}
vector<vector<int>>pascalTriangle(int n){
    vector<vector<int>>ans;
    for(int row=1;row<=n;row++){
        vector<int>tempList;
        for(int col=1;col<=row;col++){
            cout<<nCr(row,col)<<",";
            tempList.push_back(nCr(row-1,col-1));
        }
        ans.push_back(tempList);
    }
    cout<<endl;
    return ans;
}

void printVal(int n, int r){
    long long res=1; // initial result
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    cout<<res;
}

void printRowVal(int row){
    long long res=1;
    for(int i=0;i<row;i++){
        cout<<res;
        res=res*(row-i);
        res=res/(i+1);
    }
    cout<<res;
}
int main(){
    int r=4,c=2;
    printVal(r,c);
    cout<<endl;
    printRowVal(4);
    vector<vector<int>>ans=pascalTriangle(r);
    for(auto it:ans){
        for(auto i:it)
            cout<<i;
            cout<<endl;
    }

}