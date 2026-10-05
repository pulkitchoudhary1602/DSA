class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return fun(s,0,n-1,dp);
    }
    int fun(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){

            return dp[i][j]=fun(s,i+1,j-1,dp);
        }
        return dp[i][j]=1+min(fun(s,i+1,j,dp),fun(s,i,j-1,dp));
    }
};