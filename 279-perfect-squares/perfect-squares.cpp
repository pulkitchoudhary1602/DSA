class Solution {
public:
    int solve(int n,vector<int>&perfect,vector<int>&dp){
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        if(dp[n]!=-1) return dp[n];
        int mini=INT_MAX;
        for(int i=0;i<perfect.size();i++){
            int ans=solve(n-perfect[i],perfect,dp);
            if(ans!=INT_MAX){
                mini=min(mini,ans+1);
            }
        }
        dp[n]=mini;
        return dp[n];
    }
    int numSquares(int n) {
       vector<int>perfect;
       for(int i=1;i*i<=n;i++){
        perfect.push_back(i*i);
       }
       vector<int>dp(n+1,-1);
        int ans=solve(n,perfect,dp);
        if(ans==INT_MAX) return 0;
        return ans;
    }
};