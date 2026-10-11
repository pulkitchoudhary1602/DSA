class Solution {
public:
    int rob(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return fun(arr,0,n,dp);
    }
    int fun(vector<int>&arr,int index,int n,vector<int>&dp){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int include=arr[index]+fun(arr,index+2,n,dp);
        int exclude=fun(arr,index+1,n,dp);
        return dp[index]=max(include,exclude);

    }
};