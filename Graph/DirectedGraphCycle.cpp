#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void printGraph(vector<vector<int>>adjLis,int n){
    for(int i=0;i<n;i++){
        for(auto it:adjLis[i])
        cout<<it<<",";

    }
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // prerequisites means Directed Graph or Topological Sort / Dependency
        // [dependent, dependency]
        // later resolve, first resolve
        // ->
        // create adjLis
        vector<vector<int>>adjLis(numCourses);
        // vector<vector<int>>adjLis(numCourses,vector<int>);
        for(int i=0;i<numCourses;i++){
            adjLis[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        printGraph(adjLis,numCourses);
        return {};
    }
};
int main(){
     Solution sol=new Solution();
     sol.findOrder
}