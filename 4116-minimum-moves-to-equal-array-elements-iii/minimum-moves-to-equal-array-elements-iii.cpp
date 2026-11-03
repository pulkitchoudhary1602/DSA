class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=0;
        int sum=0;
        int n=nums.size();
       for(int i=0;i<n;i++){
        sum+=nums[i];
        maxi=max(maxi,nums[i]);
       }
       return maxi*n-sum;
    }
};