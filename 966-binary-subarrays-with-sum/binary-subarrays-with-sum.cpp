class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (function(nums,goal)-function(nums,goal-1));
    }
    int function(vector<int>& nums, int goal){
        if (goal<0) return 0;
        int l=0;
        int r=0;
        int n=nums.size();
        int cnt=0;
        int sum=0;
        while(r<n){
            sum=sum+nums[r];
            while(sum>goal){
                sum=sum-nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
};