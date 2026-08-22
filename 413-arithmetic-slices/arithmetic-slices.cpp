class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int cnt=0,ans=0,n=nums.size();
        if(n<3) return 0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                cnt++;
                ans=ans+cnt;
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
};