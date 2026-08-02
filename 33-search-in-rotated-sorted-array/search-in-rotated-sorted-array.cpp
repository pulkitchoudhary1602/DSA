class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int index=mini(nums);
        if(target>nums[n-1]){  //target is left of index
            int low=0;
            int high=index-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high=mid-1;
                else low=mid+1;
            }
            return -1;

        }
        else{  //target is right of index
            int low=index;
            int high=n-1;
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) high=mid-1;
                else low=mid+1;
            }
            return -1;
        }
    }
    int mini(vector<int>& nums){
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]>nums[n-1]) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};