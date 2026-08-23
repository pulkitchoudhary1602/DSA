class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int be=nums[0];
        int me=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=be*nums[i];
            int v3=me*nums[i];
            be=max(v1,max(v2,v3));
            me=min(v1,min(v2,v3));
            ans=max(ans,max(be,me));
        }
        return ans;
    }
};