class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left=0,right=0,sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if(sum-nums[0]==0) return 0;
        for(int i=1;i<n;i++){
            left+=nums[i-1];
            right=sum-nums[i]-left;
            if(left==right){
                return i;
            }
        }
        return -1;
    }
};