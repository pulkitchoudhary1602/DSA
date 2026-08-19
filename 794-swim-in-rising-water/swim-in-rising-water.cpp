class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int low=grid[0][0];
        int high=grid[0][0];
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                high=max(high,grid[i][j]);
            }
        }
        int ans=0;
        while(low<=high){
           int mid=(low+high)/2;
            if(function(grid,n,m,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    bool function(vector<vector<int>>& grid,int n,int m,int money){
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        queue<pair<int,int>>q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(row==n-1 && col==m-1) return true;
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0 && money>=grid[nrow][ncol]){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return false;
    }
};