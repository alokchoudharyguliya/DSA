#include<bits/stdc++.h>
using namespace std;
int main(){
    
    vector<int> arr = {2, 1, 5, 1, 3, 6, 7, 4, 3, 6, 5};
    stack<int> st;
    // creating a double sized array that is we will check only for 2*n sized array add n to the index
    vector<int>res(arr.size(),-1);

    for(int i=2*arr.size()-1;i>=0;i--){
        int ind=i%arr.size();
        while(!st.empty()&&arr[ind]>st.top()){
            st.pop();
        }
        if(st.empty()){
            res[ind]=-1;
        }
        else
        res[ind]=st.top();
        st.push(arr[ind]);
    }
    for(auto i:res)
    cout<<i<<",";

}