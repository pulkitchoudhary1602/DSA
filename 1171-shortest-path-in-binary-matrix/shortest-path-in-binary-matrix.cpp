class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1){
            return -1;
        }
        if(n==1){
            if(grid[0][0]==1) return -1;
            else return 1;
        }
        int mini=INT_MAX;
        vector<vector<int>>vis(n,vector(m,0));
        int delrow[8] = {-1,-1,-1,0,0,1,1,1};
        int delcol[8] = {-1,0,1,-1,1,-1,0,1};
        queue<pair<pair<int,int>,int>>q;  //{{row,col},dist}
        q.push({{0,0},1});
        vis[0][0]=1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && vis[nrow][ncol]==0){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                    if(nrow==n-1 && ncol==m-1){
                        mini=min(mini,dist+1);
                    }
                }
            }
        }
        if(mini==INT_MAX) return -1;
        else return mini;
    }
};