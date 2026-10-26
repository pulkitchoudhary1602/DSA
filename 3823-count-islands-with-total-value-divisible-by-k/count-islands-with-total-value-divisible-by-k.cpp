class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,1,-1};
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long long sum=0;
                if(grid[i][j]!=0 && vis[i][j]==0){
                    dfs(grid,vis,dx,dy,i,j,sum,n,m);
                    if(sum%k==0){
                    ans++;
                }
                }
            }
        }
        return ans;    
    }
    void dfs(vector<vector<int>>&grid,vector<vector<int>>&vis,int dx[],int dy[],int i,int j,long long &sum,int n,int m){
        vis[i][j]=1;
        sum+=grid[i][j];
        for(int k=0;k<4;k++){
            int nrow=dx[k]+i;
            int ncol=dy[k]+j;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && grid[nrow][ncol]!=0){
                dfs(grid,vis,dx,dy,nrow,ncol,sum,n,m);
            }
        }
    }
};