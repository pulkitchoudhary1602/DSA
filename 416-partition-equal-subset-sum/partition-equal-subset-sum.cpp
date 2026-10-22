class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return fun(arr,n-1,target,dp);
    }
    bool fun(vector<int>&arr,int idx,int target,vector<vector<int>>&dp){
        if(target==0) return true;
        if(idx==0) return arr[0]==target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool take=false;
        bool nottake=false;
        nottake=fun(arr,idx-1,target,dp);
        if(target>=arr[idx]) take=fun(arr,idx-1,target-arr[idx],dp);
        return dp[idx][target]= take||nottake;
    }
};