class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fun(coins,amount,n-1,dp);
    }
    int fun(vector<int>&coins,int sum,int idx,vector<vector<int>>&dp){
        if(idx==0){
            if(sum%coins[0]==0) return 1;
            return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int nottake=fun(coins,sum,idx-1,dp);
        int take=0;
        if(sum>=coins[idx]){
            take=fun(coins,sum-coins[idx],idx,dp);
        }
        return dp[idx][sum]= take+nottake;
    }
};