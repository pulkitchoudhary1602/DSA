class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0,n=nums.size();
        unordered_map<int,int>f;
        f[0]=1;
        int ans=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            ans=ans+f[sum-k];
            f[sum]++;
        }
        return ans;
    }
};