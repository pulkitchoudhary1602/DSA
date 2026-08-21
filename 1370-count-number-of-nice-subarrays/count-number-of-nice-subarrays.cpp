class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (function(nums,k)-function(nums,k-1));
    }
    int function(vector<int>& nums, int k){
        if(k<0) return 0;
        int l=0,r=0,cnt=0,n=nums.size(),sum=0;
        while(r<n){
            sum=sum+nums[r]%2;
            while(sum>k){
                sum=sum-nums[l]%2;
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
};