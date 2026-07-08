class Solution {
public:
    int solve(vector<int>&nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int incl=nums[i]+solve(nums,i+2,dp);
        int excl=solve(nums,i+1,dp);
        dp[i]=max(incl,excl);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>first;
        vector<int>second;
        for(int i=0;i<n;i++)
        {
            if(i!=0){
                second.push_back(nums[i]);
            }
            if(i!=n-1){
                first.push_back(nums[i]);
            }
        }
        int a=0;
        int b=0;
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(solve(first,a,dp1),solve(second,b,dp2));
    }
};