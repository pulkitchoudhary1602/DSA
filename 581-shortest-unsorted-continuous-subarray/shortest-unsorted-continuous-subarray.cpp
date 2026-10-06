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