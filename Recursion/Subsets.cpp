#include<bits/stdc++.h>
using namespace std;
void solve(vector<int>&nums,vector<vector<int>>&res,int ind,vector<int>&curr){
    if(ind==nums.size()){
        res.push_back(curr);
        return;
    }
    curr.push_back(nums[ind]);
    solve(nums,res,ind+1,curr);
    curr.pop_back();
    solve(nums,res,ind+1,curr);
}
vector<vector<int>>subsets(vector<int>&nums){
    vector<vector<int>>res;
    vector<int>curr={};
    solve(nums,res,0,curr);
    return res;
}
int main(){
    vector<int>nums={1,2,3};
    vector<vector<int>>res=subsets(nums);
    for(auto i:res){
        for(auto it:i)
            cout<<it<<",";
        cout<<endl;
    }

}