
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // obtain the number of rotten oranges
        int cntRottenOrang = 0;
        int totalOrange = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    // cntRottenOrang++;
                    q.push({i,j});
                }
                if (grid[i][j] != 0)
                    totalOrange++;
            }
        }
                    int delRow[4]={-1,0,1,0};
                    int delCol[4]={0,1,0,-1};
        int days=0;
            while(!q.empty()){
                int k=q.size();
                cntRottenOrang+=k;
                while(k--){
                    auto node=q.front();
                    int row=node.first;
                    int col=node.second;
                    // cout<<"{"<<row<<col<<"}";
                    q.pop();
                    for(int i=0;i<4;i++){
                        int newrow=row+delRow[i];
                        int newcol=col+delCol[i];
                        if(newrow<0||newcol<0||newrow>=grid.size()||newcol>=grid[0].size()||grid[newrow][newcol]!=1)continue;
                        grid[newrow][newcol]=2;
                        q.push({newrow,newcol});
                    }
                }
                if(!q.empty())
                days++;

            }
            return cntRottenOrang==totalOrange?days:-1;
   }
};