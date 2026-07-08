class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int incl=nums[i]+solve(nums,i+2,dp);
        int excl=solve(nums,i+1,dp);
        dp[i]= max(incl,excl);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int i=0;
        vector<int>dp(nums.size(),-1);
        int ans=solve(nums,i,dp);
        return ans;
    }
};