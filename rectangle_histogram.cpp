#include<bits/stdc++.h>
using namespace std;

// int largestArea(int arr[],int n){

//     int maxArea=0;
//     for(int i=0;i<n;i++){

//         int minH=INT_MAX;
//         for(int j=i;j<n;i++){
//             minH=min(minH,arr[j]);
//             int width=j-i+1;
//             int area=minH*width;
//             maxArea=max(area,maxArea);
//         }
//     }
//     return maxArea;
// }

int largestRectangleArea(vector<int>&heights){
    int n=heights.size();

    stack<int>st;

    int leftsmall[n],rightsmall[n];
    // Compute nearest smallesr to left(NSL) for each bar
    for(int i=0;i<n;i++){
        while(!st.empty()&&heights[st.top()]>=heights[i])
        st.pop();
        leftsmall[i]=st.empty()?0:st.top()+1;
        st.push(i);
    }
    while(!st.empty())st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&heights[st.top()]>=heights[i])st.pop();
        rightsmall[i]=st.empty()?n-1:st.top()-1;
        st.push(i);
    }
    int maxA=0;
    for(int i=0;i<n;i++){
int width=rightsmall[i]-leftsmall[i]+1;
        maxA=max(maxA,heights[i]*width);
    }
    return maxA;
}
int main(){
    // int arr[]= {2, 1, 5, 6, 2, 3, 1};
    vector<int>arr= {2, 1, 5, 6, 2, 3, 1};
    int n=7;
    cout<<"The largest area is "<<largestRectangleArea(arr)<<endl;
    return 0;
}