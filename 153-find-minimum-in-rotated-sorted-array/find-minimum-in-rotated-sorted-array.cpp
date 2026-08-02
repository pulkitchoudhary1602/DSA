class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]>nums[n-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};