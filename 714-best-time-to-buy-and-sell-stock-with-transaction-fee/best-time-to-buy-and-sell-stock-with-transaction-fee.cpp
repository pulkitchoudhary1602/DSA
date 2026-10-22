/*
class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return fun(arr,fee,n,0,1,dp);
    }
    int fun(vector<int>&arr,int fee,int n,int idx,int buy,vector<vector<int>>&dp){
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=0;
        if(buy){
            profit=max(-arr[idx]+fun(arr,fee,n,idx+1,0,dp),fun(arr,fee,n,idx+1,1,dp));
        }
        else{
            profit=max(arr[idx]-fee+fun(arr,fee,n,idx+1,1,dp),fun(arr,fee,n,idx+1,0,dp));
        }
        return dp[idx][buy]= profit;
    }
};
*/
class Solution {
public:
    int maxProfit(vector<int>& arr, int fee) {
        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-arr[idx]+dp[idx+1][0],dp[idx+1][1]);
                }
                else{
                    profit=max(arr[idx]-fee+dp[idx+1][1],dp[idx+1][0]);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};