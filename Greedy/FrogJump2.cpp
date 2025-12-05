#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    int minJumps(vector<int>&nums,int position){
        if(position>=nums.size()-1)return 0;
        if
    }
    public:
    int jump(vector<int>&nums){
        return minJumps(nums,0);
    }
};
int main(){
    vector<int>nums={2,3,1,1,4};
    Solution sol;
    cout<<sol.jumps(nums)<<endl;
    return 0;
}