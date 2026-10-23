class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if((total-target)%2==1) return 0;
        if(abs(target)>total) return  0;
        sum=(total-target)/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return fun(nums,sum,n-1,dp);
    }
    int fun(vector<int>&nums,int sum,int idx,vector<vector<int>>&dp){
        if(idx==0){
            if(sum==0 && nums[0]==0) return 2;
            if(sum==0 || sum==nums[0]) return 1;
            return 0;
        }
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take=0;
        int nottake=fun(nums,sum,idx-1,dp);
        if(sum>=nums[idx]){
            take=fun(nums,sum-nums[idx],idx-1,dp);
        }
        return dp[idx][sum]= take+nottake;
    }
};