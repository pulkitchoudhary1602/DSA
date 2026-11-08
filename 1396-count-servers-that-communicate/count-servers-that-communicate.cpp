class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int total=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    total+=1;
                    if(!fun(grid,i,j,n,m)){
                        cnt++;
                    }
                }
            }
        }
        return total-cnt;
    }
    bool fun(vector<vector<int>>& grid,int row,int col,int n,int m){
        for(int j=0;j<m;j++){ //row traversal
            if(j!=col && grid[row][j]==1){
                return true;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=row && grid[i][col]==1){
                return true;
            }
        }
        return false;
    }
};