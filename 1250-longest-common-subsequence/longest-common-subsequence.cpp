class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(s1,s2,n,m,0,0,dp);
    }
    int fun(string &s1, string &s2,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= 1+fun(s1,s2,n,m,i+1,j+1,dp);
        return dp[i][j]= max(fun(s1,s2,n,m,i+1,j,dp),fun(s1,s2,n,m,i,j+1,dp));
    }
};