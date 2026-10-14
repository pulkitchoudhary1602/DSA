class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int maxending=nums[0];
        int minending=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=maxending*nums[i];
            int v3=minending*nums[i];
            maxending=max({v1,v2,v3});
            minending=min({v1,v2,v3});
            ans=max({ans,maxending,minending});
        }
        return ans;
    }
};