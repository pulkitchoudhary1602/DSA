class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return function(nums,k)-function(nums,k-1);
    }
    int function(vector<int>& nums, int k){
        if(k<0) return 0;
        int n=nums.size(),l=0,r=0,cnt=0;
        unordered_map<int,int>mpp; //{num,freq};
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            cnt=cnt+r-l+1;
            r++;
        }
        return cnt;
    }
};