class Solution {
public:
    int solve(vector<int>&nums){
        int prev=nums[0];
        int previndex=1;
        int k=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]!=prev){
                prev=nums[i];
                swap(nums[i],nums[previndex]);
                previndex++;
                k++;
            }
        }
        return previndex;
    }
    int removeDuplicates(vector<int>& nums) {
        int k=solve(nums);
        return k;

    }
};