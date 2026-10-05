class Solution {
public:
    int minDistance(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(s1,s2,n,m,0,0,dp);
    }
    int fun(string &s1,string &s2,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=fun(s1,s2,n,m,i+1,j+1,dp);
        int insrt=fun(s1,s2,n,m,i,j+1,dp);
        int del=fun(s1,s2,n,m,i+1,j,dp);
        int rep=fun(s1,s2,n,m,i+1,j+1,dp);
        return dp[i][j]=1+min({insrt,del,rep});
    }
};