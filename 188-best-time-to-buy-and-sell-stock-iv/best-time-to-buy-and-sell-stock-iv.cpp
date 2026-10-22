class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return fun(arr,n,0,1,k,dp);
    }
    int fun(vector<int>&arr,int n,int idx,int buy,int cap, vector<vector<vector<int>>>&dp){
        if(cap==0 || idx==n) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-arr[idx]+fun(arr,n,idx+1,0,cap,dp),fun(arr,n,idx+1,1,cap,dp));
        }
        else{
            profit=max(arr[idx]+fun(arr,n,idx+1,1,cap-1,dp),fun(arr,n,idx+1,0,cap,dp));
        }
        return dp[idx][buy][cap]= profit;
    }
};