class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>>arr(n+1);
        for(int i=0;i<times.size();i++){
            int s=times[i][0];
            int d=times[i][1];
            int dist=times[i][2];
            arr[s].push_back({d,dist});
        }
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(d>dist[node]) continue;
            for(int i=0;i<arr[node].size();i++){
                int neigh=arr[node][i].first;
                int wt=arr[node][i].second;
                if(d+wt<dist[neigh]){
                    pq.push({d+wt,neigh});
                    dist[neigh]=d+wt;
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            else{
                maxi=max(maxi,dist[i]);
            }
        }
        return maxi;
    }
};