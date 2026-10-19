class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int sml=0;
        int big;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<target){
                sml++;
            }
            else if(nums[i]==target){
                cnt++;
            }
        }
        big=sml+cnt;
        vector<int>ans;
        for(int i=sml;i<big;i++){
            ans.push_back(i);
        }
        return ans;
    }
};