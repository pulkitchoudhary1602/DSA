class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        int total=0;
        int cnt=0;
        int tm=0;
        queue<pair<pair<int,int>,int>>q; //q->{{r,c},t}
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    total++;
                }
            }
        }
        int delrow[]={-1,1,0,0};
        int delcol[]={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(t,tm);
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && vis[nrow][ncol]==0){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=1;
                    cnt++;
                }
            }
        }
        if(total==cnt) return tm;
        return -1;
    }
};