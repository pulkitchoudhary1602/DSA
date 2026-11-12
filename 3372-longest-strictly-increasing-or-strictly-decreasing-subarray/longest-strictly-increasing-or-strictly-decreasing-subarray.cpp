class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int v1=1;
        int v2=1;
        for(int i=1;i<n;i++){
            //increasing
            if(nums[i-1]<nums[i]){
                v1+=1;
            }
            else{
                v1=1;
            }
            //decreasing
            if(nums[i-1]>nums[i]){
                v2+=1;
            }
            else{
                v2=1;
            }
            ans=max({ans,v1,v2});
        }
        return ans;
    }
};