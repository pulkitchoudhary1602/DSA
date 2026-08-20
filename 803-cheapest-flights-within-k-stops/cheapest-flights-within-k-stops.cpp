class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> temp=dist;
            for(int j=0;j<flights.size();j++){
                int s=flights[j][0];
                int d=flights[j][1];
                int w=flights[j][2];
                if(dist[s]!=INT_MAX && temp[d]>dist[s]+w){
                    temp[d]=dist[s]+w;
                }
            }
            dist=temp;
        }
        if(dist[dst]==INT_MAX) return -1;
        else return dist[dst];
    }
};