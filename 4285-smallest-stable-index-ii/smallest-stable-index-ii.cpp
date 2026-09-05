class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr(n);
        arr[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            arr[i]=min(arr[i+1],nums[i]);
        }
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            if(maxi-arr[i]<=k) return i;
        }
        return -1;
    }
};