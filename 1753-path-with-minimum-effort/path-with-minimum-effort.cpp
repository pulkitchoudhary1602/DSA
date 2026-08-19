class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int delrow[4]={-1,1,0,0};
        int delcol[4]={0,0,-1,1};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(d>dist[row][col]) continue;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int absdiff=abs(heights[row][col]-heights[nrow][ncol]);
                    int newwt=max(d,absdiff);
                    if(newwt<dist[nrow][ncol]){
                        dist[nrow][ncol]=newwt;
                        pq.push({newwt,{nrow,ncol}});
                    }
                }
            }
        }
    return dist[n-1][m-1];
    }
};