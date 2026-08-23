class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bemax=nums[0],bemin=nums[0],n=nums.size(),ansmax=nums[0],ansmin=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=nums[i]+bemax;
            int v3=nums[i]+bemin;
            bemax=max(v1,v2);
            bemin=min(v1,v3);
            ansmax=max(ansmax,bemax);
            ansmin=min(ansmin,bemin);
        }
        return max(ansmax,abs(ansmin));
    }
};