class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans=0;
        int mini=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            ans+=nums[i]-mini;
        }
        return ans;
    }
};