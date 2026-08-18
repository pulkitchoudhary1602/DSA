class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans=true;
        vector<int> colors(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(colors[i]==-1){
                dfs(graph,colors,i,0,ans);
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& graph,vector<int>&colors,int node,int c,bool &ans){
        colors[node]=c;
        for(int i=0;i<graph[node].size();i++){
            int temp=graph[node][i];
            if(colors[temp]==c) ans=false;
            if(colors[temp]==-1) dfs(graph,colors,temp,1-c,ans);
        }
    }
};