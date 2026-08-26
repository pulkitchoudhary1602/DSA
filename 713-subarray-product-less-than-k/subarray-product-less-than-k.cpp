class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
       int n=nums.size();
       int l=0,r=0;
       int cnt=0;
       int prod=1;
       while(r<n){
        prod=prod*nums[r];
        while(prod>=k && l<n){
            prod=prod/nums[l];
            l++;
        }
        cnt=cnt+(r-l+1);
        r++;
       } 
       return cnt;
    }
};