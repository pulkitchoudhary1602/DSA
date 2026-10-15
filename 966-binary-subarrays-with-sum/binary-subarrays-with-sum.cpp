class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return fun(nums,goal)-fun(nums,goal-1);
    }
    int fun(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0,r=0,sum=0,cnt=0;
        int n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal){
                cnt+=r-l+1;
            }
            r++;
        }
        return cnt;
    }
};