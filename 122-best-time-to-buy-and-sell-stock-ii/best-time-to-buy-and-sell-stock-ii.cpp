class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //idx,buy or not buy
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return fun(prices,0,1,n,dp); //1->buy,0->not buy
    }
    int fun(vector<int>& prices,int idx,int buy,int n,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if (dp[idx][buy]!=-1)  return dp[idx][buy];
        int profit;
        if(buy){
            profit=max(-1*prices[idx]+fun(prices,idx+1,0,n,dp),fun(prices,idx+1,1,n,dp));
        }
        else{
            profit=max(prices[idx]+fun(prices,idx+1,1,n,dp),fun(prices,idx+1,0,n,dp));
        }
        return dp[idx][buy]= profit;
    }
};