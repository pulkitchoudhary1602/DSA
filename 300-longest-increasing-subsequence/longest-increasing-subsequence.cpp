//f(index,prev_index) //prev_idx=last index of increasing number

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(nums,0,-1,dp);
    }
    int fun(vector<int>&nums,int idx,int prev_idx,vector<vector<int>>&dp){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        int nottake=0+fun(nums,idx+1,prev_idx,dp);
        int take=0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]){
            take=1+fun(nums,idx+1,idx,dp);
        }
        return dp[idx][prev_idx+1]=max(take,nottake);
    }
};