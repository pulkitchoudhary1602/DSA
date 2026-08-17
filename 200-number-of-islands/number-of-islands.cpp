class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    res++;
                    dfs(grid,vis,n,m,row,col,i,j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int n,int m,int row[],int col[],int i,int j){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int nrow=i+row[k];
            int ncol=j+col[k];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && vis[nrow][ncol]==0){
                dfs(grid,vis,n,m,row,col,nrow,ncol);
            }
        }
    }
};