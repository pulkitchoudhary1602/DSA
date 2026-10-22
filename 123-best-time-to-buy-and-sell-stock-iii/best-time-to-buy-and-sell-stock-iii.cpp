/*
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return fun(arr,n,0,1,2,dp);
    }
    int fun(vector<int>& arr,int n,int idx,int buy,int cap,vector<vector<vector<int>>>&dp){
        if(cap==0 || idx==n) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-arr[idx]+fun(arr,n,idx+1,0,cap,dp),0+fun(arr,n,idx+1,1,cap,dp));
        }
        else{
            profit=max(arr[idx]+fun(arr,n,idx+1,1,cap-1,dp),fun(arr,n,idx+1,0,cap,dp));
        }
        return dp[idx][buy][cap]= profit;
    }
};
*/
class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1))); //idx,buy,cap
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++){
                dp[n][buy][cap]=0;
            }
        }
        for(int idx=0;idx<=n;idx++){
            for(int buy=0;buy<=1;buy++){
                dp[idx][buy][0]=0;
            }
        }
        for(int idx=n-1;idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int profit=0;
                    if(buy){
                        profit=max(-arr[idx]+dp[idx+1][0][cap],dp[idx+1][1][cap]);
                    }
                    else{
                        profit=max(arr[idx]+dp[idx+1][1][cap-1],dp[idx+1][0][cap]);
                    }
                    dp[idx][buy][cap]=profit;
                }
            }
        }
        return dp[0][1][2];
    }
};