/*
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>temp=nums;
        sort(temp.begin(),temp.end());
        int n=nums.size();
        int left=0;
        while(left<n && nums[left]==temp[left]){
            left++;
        }
        if(left==n) return 0;
        int right=n-1;
        while(right>=0 && nums[right]==temp[right]){
            right--;
        }
        return (right-left+1);
    }
};
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left=0;
        int n=nums.size();
        while(left<n-1 && nums[left]<=nums[left+1]){
            left++;
        }
        if(left==n-1) return 0;
        int right=n-1;
        while(right>0 && nums[right]>=nums[right-1]){
            right--;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=left;i<=right;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        while(left>0 && nums[left-1]>mini){
            left--;
        }
        while(right<n-1 && nums[right+1]<maxi){
            right++;
        }
        return right-left+1;
    }
};