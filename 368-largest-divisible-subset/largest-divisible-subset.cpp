class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),hash(n);
        int lastindex=0;
        int maxi=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<dp[prev]+1){
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                    }
                }
                if(dp[i]>maxi){
                    maxi=dp[i];
                    lastindex=i;
            }
        }
        vector<int>ans;
        ans.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            ans.push_back(nums[lastindex]);
        }
        return ans;    
    }
};