class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int cnt1=0;
        int cnt2=0;
        int n=s1.size();
        int m=s2.size();
        for(int i=0;i<n;i++){
            cnt1+=(int)s1[i];
        }
        for(int i=0;i<m;i++){
            cnt2+=(int)s2[i];
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int cnt3=fun(s1,s2,n,m,0,0,dp);
        return cnt1+cnt2-2*cnt3;
    }
    int fun(string &s1,string &s2,int n,int m,int i,int j,vector<vector<int>>&dp){
        if(i==n || j==m){
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=s1[i]+fun(s1,s2,n,m,i+1,j+1,dp);
        }
        return dp[i][j]=max(fun(s1,s2,n,m,i+1,j,dp),fun(s1,s2,n,m,i,j+1,dp));
    }
};