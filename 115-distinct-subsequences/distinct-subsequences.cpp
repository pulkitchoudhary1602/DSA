class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(s,t,n,m,0,0,dp);
    }
    int fun(string &s, string &t,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]= fun(s,t,n,m,i+1,j+1,dp)+fun(s,t,n,m,i+1,j,dp);
        }
        return dp[i][j]= fun(s,t,n,m,i+1,j,dp);
    }
};