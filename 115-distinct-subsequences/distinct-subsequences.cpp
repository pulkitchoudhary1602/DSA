class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));
        
        return fun(s,t,0,0,dp);
    }
    long long fun(string &s, string &t,int i,int j,vector<vector<long long>> &dp){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        long long ans=0;
        if(s[i]!=t[j]){
            ans = fun(s,t,i+1,j,dp);
        }
        else{
            ans = fun(s,t,i+1,j+1,dp);
            ans += fun(s,t,i+1,j,dp);
        }
        return dp[i][j] = ans;
    }
};