class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        lb(nums,target,ans);
        ub(nums,target,ans);
        return ans;
    }
    void lb(vector<int>& nums, int target,vector<int>&ans){
        int low=0;
        int high=nums.size()-1;
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){ 
                res=mid;
                high=mid-1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        ans[0]=res;
    }
    void ub(vector<int>& nums, int target,vector<int>&ans){
        int low=0;
        int high=nums.size()-1;
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){ 
                res=mid;
                low=mid+1;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        ans[1]=res;
    }
};