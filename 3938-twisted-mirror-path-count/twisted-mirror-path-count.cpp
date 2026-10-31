class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=1e9+7;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return dfs(grid,n,m,0,0,0,mod,dp);
    }

    int dfs(vector<vector<int>>& grid,int n,int m,int i,int j,int dir,int mod,vector<vector<vector<int>>>& dp) {
        if(i>=n||j>=m) return 0;
        if(i==n-1&&j==m-1) return 1;
        if(dp[i][j][dir]!=-1) return dp[i][j][dir];
        int total=0;
        if(grid[i][j]==1) {
            if(dir==1) total=dfs(grid,n,m,i,j+1,0,mod,dp);
            else total=dfs(grid,n,m,i+1,j,1,mod,dp);
        } else {
            total=dfs(grid,n,m,i+1,j,1,mod,dp);
            total=(total+dfs(grid,n,m,i,j+1,0,mod,dp))%mod;
        }
        return dp[i][j][dir]=total;
    }
};